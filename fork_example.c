// Demonstra gerenciamento de processos

// Compilação e execução:
//   gcc fork_example.c -o fork_example
//   ./fork_example

#include <stdio.h>    // printf
#include <unistd.h>   // fork

int main() {

    pid_t pid = fork();  // Cria um processo filho
    
    if (pid == 0) {
        // ================================
        // Processo Filho
        // ================================
        printf("Sou o processo filho! PID=%d\n", getpid());
    } else {
        // ================================
        // Processo Pai
        // ================================
        printf("Sou processo Pai! PID = %d, filho =%d \n", getpid(), pid);
    }
    return 0;
}
