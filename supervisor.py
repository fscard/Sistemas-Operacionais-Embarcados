"""
supervisor.py
Pai cria filhos e monitora seus estados em tempo real

Execução:
    python3 supervisor.py

Em outro terminal, você pode enviar sinais:
    kill -STOP <PID_FILHO>   # coloca o filho em estado T (Stopped)
    kill -CONT <PID_FILHO>   # retoma filho
    kill -TERM <PID_FILHO>   # encerra filho
"""

import os
import signal

def filho():
    # Cada filho fica em loop infinito, apenas aguardando sinais
    print(f"Filho iniciado, PID={os.getpid()}")
    while True:
        signal.pause()  # bloqueia até receber um sinal

def pai_supervisor():
    # Cria primeiro filho
    pid1 = os.fork()
    if pid1 == 0:
        filho()
        os._exit(0)

    # Cria segundo filho
    pid2 = os.fork()
    if pid2 == 0:
        filho()
        os._exit(0)

    print(f"Pai supervisor PID={os.getpid()} criou filhos: {pid1}, {pid2}")

    # Loop de supervisão
    while True:
        # WUNTRACED = 2, WCONTINUED = 8 (valores das flags no Linux)
        wpid, status = os.waitpid(-1, os.WUNTRACED | os.WCONTINUED)

        if os.WIFEXITED(status):
            print(f"Filho {wpid} terminou normalmente com código {os.WEXITSTATUS(status)}")
        elif os.WIFSIGNALED(status):
            print(f"Filho {wpid} morreu por sinal {os.WTERMSIG(status)}")
        elif os.WIFSTOPPED(status):
            print(f"Filho {wpid} foi PARADO (SIGSTOP ou Ctrl+Z), sinal={os.WSTOPSIG(status)}")
        elif os.WIFCONTINUED(status):
            print(f"Filho {wpid} foi CONTINUADO (SIGCONT)")

if __name__ == "__main__":
    pai_supervisor()
