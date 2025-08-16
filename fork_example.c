//  Demonstra multitarefa e o gerenciamento de processos.
//  gcc fork_example.c -o fork_example
//  ./fork_example


#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // cria um processo filho

    if (pid == 0) {
        // Código do processo filho
        printf("Sou o processo filho! PID = %d\n", getpid());
    } else {
        // Código do processo pai
        printf("Sou o processo pai! PID = %d, filho = %d\n", getpid(), pid);
    }

    return 0;
}
