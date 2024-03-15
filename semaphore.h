#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <pthread.h>
#include <semaphore.h>

/*

Instituto Tecnológico de Costa Rica | Ing. Computación

Sistemas Operativos - Tarea #2

Elaborado Por:
Adrián Herrera
Rebeca Madrigal
Ronaldo Vindas

*/

typedef struct {
    sem_t semaphore;
} Semaphore;

void semaphore_init(Semaphore *s, int initial_value);

void semaphore_wait(Semaphore *sem);

void semaphore_signal(Semaphore *sem);


#endif // SEMAPHORE_H