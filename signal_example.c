// Tratando sinais (interrupções no espaço do usuário)
// Demonstra como capturar e tratar sinais com signal handling.
//
// Compilação e execução:
//   gcc signal_example.c -o signal_example
//   ./signal_example
// Depois pressione Ctrl+C no terminal para enviar SIGINT ao processo.

#include <stdio.h>    // printf
#include <signal.h>   // signal, SIGINT
#include <unistd.h>   // sleep
#include <stdlib.h>   // exit

// Função "handler": será chamada automaticamente quando o sinal for recebido
void handler(int sig) {
    // 'sig' é o número do sinal recebido (ex.: SIGINT = 2)
    printf("Recebi sinal %d! Encerrando programa...\n", sig);

    // encerra o programa de forma controlada
    exit(0);
}

int main() {
    // Associa o sinal SIGINT (gerado ao pressionar Ctrl+C)
    // à função handler definida acima.
    // Isso substitui o comportamento padrão (que seria encerrar o processo imediatamente).
    signal(SIGINT, handler);

    // Loop infinito simulando execução contínua do programa
    while (1) {
        printf("Executando... pressione Ctrl+C\n");
        sleep(1); // aguarda 1 segundo antes de imprimir de novo
    }

    return 0; // nunca chega aqui, pois o programa termina no handler
}
