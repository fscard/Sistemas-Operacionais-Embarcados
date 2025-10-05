#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

/* ---------- Task 1 ---------- */
void vTaskA(void *pvParameters) {
    while (1) {
        printf("Task A executando...\n");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

/* ---------- Task 2 ---------- */
void vTaskB(void *pvParameters) {
    while (1) {
        printf("Task B executando...\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

/* ---------- Task 3 ---------- */
void vTaskC(void *pvParameters) {
    while (1) {
        printf("Task C executando...\n");
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
}

/* ---------- Ponto de entrada ---------- */
int main(void) {
    printf("=== FreeRTOS: Exemplo com 3 Tasks ===\n");

    /* Cria 3 tasks com diferentes prioridades */
    xTaskCreate(vTaskA, "TaskA", 1024, NULL, 2, NULL);
    xTaskCreate(vTaskB, "TaskB", 1024, NULL, 1, NULL);
    xTaskCreate(vTaskC, "TaskC", 1024, NULL, 1, NULL);

    /* Inicia o escalonador */
    vTaskStartScheduler();

    /* Se chegar aqui, houve erro */
    for(;;);
}
