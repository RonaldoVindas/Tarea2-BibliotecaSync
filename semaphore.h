/*
Instituto Tecnológico de Costa Rica | Ing. Computación | Semestre 1 - 2024

Sistemas Operativos - Tarea #2

Elaborado Por:
Adrián Herrera
Rebeca Madrigal
Ronaldo Vindas

*/


#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <pthread.h>

typedef struct {
    int value;
    pthread_mutex_t mutex;
    pthread_cond_t condition;
} Semaphore;

Semaphore* createSemaphore(int initialValue);
void destroySemaphore(Semaphore* semaphore);
void waitSemaphore(Semaphore* semaphore);
void signalSemaphore(Semaphore* semaphore);

#endif // SEMAPHORE_H
