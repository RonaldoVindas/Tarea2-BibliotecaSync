/*
Instituto Tecnológico de Costa Rica | Ing. Computación | Semestre 1 - 2024

Sistemas Operativos - Tarea #2

Elaborado Por:
Adrián Herrera
Rebeca Madrigal
Ronaldo Vindas

*/

#include <stdio.h>
#include <pthread.h>
#include "BibliotecaSync.h"

#define NUM_THREADS 2
#define NUM_ITERATIONS 5

Monitor monitor;
int contador = 0;

/*
Probar Barrera
*/

/*
Probar Monitor
*/

/*
Probar Semáforo
*/

/*   void *incrementar(void *arg) {
    int thread_index = *(int *)arg;
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        monitor_enter(&monitor);
        contador++;
        printf("Incrementado por hilo %ld: contador = %d\n", thread_index, contador);
        monitor_exit(&monitor);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    monitor_init(&monitor);

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, incrementar, (void *)&i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;               
}      */
