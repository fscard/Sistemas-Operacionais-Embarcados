// Comunicação entre processos (pipe)
// Exemplo de IPC (Inter-Process Communication) simples com pipe.
//
// Compilação e execução:
//   gcc fork_example.c -o fork_example
//   ./fork_example

#include <stdio.h>    // printf
#include <unistd.h>   // fork, pipe, read, write, close
#include <string.h>   // strlen

int main() {

    pid_t pid = fork();  // Cria um processo filho (duplica o processo atual).
    if (pid == 0) {
        // ================================
        // BLOCO DO FILHO
        // ================================
        printf("Sou processo filho! PID=%d\n", getpid());
    } else {
        // ================================
        // BLOCO DO PAI
        // ================================
        printf("Sou processo Pai! PID=%d, filho =%d \n", getpid(), pid);
    }
}
