// Preempção por fatia de tempo (time slice) – sem sleep, sem yield
// Dois threads CPU-bound, cada um tentando monopolizar a CPU. Mesmo assim, 
// ambos “andam” porque o kernel preempteia (SCHED_OTHER).
// 
// Para compilar e executar
// gcc preempt_timeslice.c -o preempt_timeslice -lpthread
// ./preempt_timeslice

#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>
#include <time.h>

atomic_ulong c1 = 0, c2 = 0;

void* t1(void* _) { for (;;) c1++; }
void* t2(void* _) { for (;;) c2++; }

int main() {
    pthread_t a, b;
    pthread_create(&a, NULL, t1, NULL);
    pthread_create(&b, NULL, t2, NULL);

    for (int i = 0; i < 10; i++) {
        struct timespec ts = { .tv_sec = 0, .tv_nsec = 300*1000*1000 }; // 300 ms
        nanosleep(&ts, NULL);
        unsigned long x = c1, y = c2;
        printf("t1=%lu  t2=%lu\n", x, y);
    }
    return 0;
}
