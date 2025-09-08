# Sistemas-Operacionais-Embarcados

Laboratório Prático – Sistemas Operacionais Embarcados (Linux)
🔧 Ambiente

Linux nativo ou em máquina virtual (Ubuntu/Debian recomendados).
Compilador GCC.
Editor de texto (nano, vim, VS Code).
Terminal Linux.

Experimento 1 – Primeira chamada de sistema

Objetivo: Entender chamadas de sistema básicas (write, _exit).

Código: hello_syscall.c

gcc hello_syscall.c -o hello

./hello

Esperado: mensagem Hello World! no terminal.


Experimento 2 – Criação de processos com fork
Objetivo: Mostrar como o Linux cria novos processos.
Código: fork_example.c

gcc fork_example.c -o fork_example

./fork_example

Esperado: duas mensagens, uma do pai e outra do filho.



Experimento 3 – Comunicação entre processos (pipe)
Objetivo: Demonstrar IPC (Inter-Process Communication).
Código: pipe_example.c

gcc pipe_example.c -o pipe_example

./pipe_example

Esperado: o pai imprime a mensagem enviada pelo filho.



Experimento 4 – Sincronização com Semáforos
Objetivo: Controlar acesso simultâneo a recursos compartilhados.
Código: semaphore_example.c

gcc semaphore_example.c -o semaphore_example -lpthread

./semaphore_example

Esperado: execução ordenada das threads sem conflito.



Experimento 5 – Tratando sinais (Ctrl+C)
Objetivo: Simular interrupções no espaço do usuário.
Código: signal_example.c

gcc signal_example.c -o signal_example

./signal_example

Esperado: ao pressionar Ctrl+C, não encerra o programa imediatamente, mas exibe mensagem de captura do sinal.

