// Demonstra multitarefa e o gerenciamento de processos.
// compilar ---- gcc fork.c -o fork
// executar ----- ./fork

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
