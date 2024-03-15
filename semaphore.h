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

// Definición de la estructura del semáforo
typedef struct {
    sem_t semaphore;
} Semaphore;

// Función para inicializar el semáforo
void semaphore_init(Semaphore *s, int value);

// Función para realizar una operación de espera en el semáforo
void semaphore_wait(Semaphore *s);

// Función para destruir el semáforo
void semaphore_signal(Semaphore *s);


#endif // BARRIER_H