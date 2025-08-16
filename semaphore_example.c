//  Controle com semáforo (POSIX)
//  Simula sincronização entre processos.

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void* tarefa(void* arg) {
    sem_wait(&sem); // espera permissão
    printf("Thread %s executando\n", (char*)arg);
    sem_post(&sem); // libera permissão
    return NULL;
}

int main() {
    pthread_t t1, t2;

    sem_init(&sem, 0, 1); // inicia com 1 recurso disponível

    pthread_create(&t1, NULL, tarefa, "A");
    pthread_create(&t2, NULL, tarefa, "B");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);
    return 0;
}
