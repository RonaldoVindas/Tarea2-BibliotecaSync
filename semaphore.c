/*
Instituto Tecnológico de Costa Rica | Ing. Computación | Semestre 1 - 2024

Sistemas Operativos - Tarea #2

Elaborado Por:
Adrián Herrera
Rebeca Madrigal
Ronaldo Vindas

*/

// semaphore.c

#include "semaphore.h"
#include <stdlib.h>

Semaphore* createSemaphore(int initialValue) {
    Semaphore* semaphore = (Semaphore*)malloc(sizeof(Semaphore));
    semaphore->value = initialValue;
    pthread_mutex_init(&semaphore->mutex, NULL);
    pthread_cond_init(&semaphore->condition, NULL);
    return semaphore;
}

void destroySemaphore(Semaphore* semaphore) {
    pthread_mutex_destroy(&semaphore->mutex);
    pthread_cond_destroy(&semaphore->condition);
    free(semaphore);
}

void waitSemaphore(Semaphore* semaphore) {
    pthread_mutex_lock(&semaphore->mutex);
    while (semaphore->value <= 0) {
        pthread_cond_wait(&semaphore->condition, &semaphore->mutex);
    }
    semaphore->value--;
    pthread_mutex_unlock(&semaphore->mutex);
}

void signalSemaphore(Semaphore* semaphore) {
    pthread_mutex_lock(&semaphore->mutex);
    semaphore->value++;
    pthread_cond_signal(&semaphore->condition);
    pthread_mutex_unlock(&semaphore->mutex);
}
