
// Compile:
// gcc rt_starvation.c -o rt_starvation
//
// Execute de forma segura:
// # prenda o programa a 1 core para evidenciar o efeito
// taskset -c 0 sudo ./rt_starvation


#define _GNU_SOURCE     // Necessário para usar sched_setscheduler
#include <stdio.h>      // printf, perror
#include <unistd.h>     // fork, sleep
#include <sched.h>      // sched_setscheduler, struct sched_param
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>   // wait
#include <signal.h>     // kill
#include <time.h>       // nanosleep

int main() {
    pid_t pid = fork();   // Criamos um processo filho

    if (pid == 0) {
        // ================================
        // FILHO: processo em tempo real
        // ================================
        struct sched_param sp;
        sp.sched_priority = 80; // Prioridade de 1 a 99 (quanto maior, mais prioridade)

        // Troca o escalonador do processo filho para SCHED_FIFO (tempo real)
        if (sched_setscheduler(0, SCHED_FIFO, &sp) != 0) {
            perror("sched_setscheduler (precisa de sudo ou cap_sys_nice)");
            exit(1);
        }

        // Loop infinito consumindo CPU sem parar (não usa sleep nem yield)
        volatile unsigned long long x = 0;
        for (;;) {
            x++; // simula carga de CPU
        }

    } else {
        // ================================
        // PAI: processo "normal" (SCHED_OTHER)
        // ================================
        for (int i = 0; i < 10; i++) {
            struct timespec ts = { .tv_sec = 0, .tv_nsec = 500*1000*1000 }; // 500 ms
            nanosleep(&ts, NULL);  // pausa o pai por 500 ms

            printf("Pai ainda vivo (i=%d)\n", i);
            fflush(stdout);
        }

        // Mata o filho após o teste, para não travar o sistema
        kill(pid, SIGKILL);
        wait(NULL);
    }
}
