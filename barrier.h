#ifndef BARRIER_H
#define BARRIER_H

#include <pthread.h>

/*
Instituto Tecnológico de Costa Rica | Ing. Computación

Sistemas Operativos - Tarea #2

Elaborado Por:
Adrián Herrera
Rebeca Madrigal
Ronaldo Vindas

*/


typedef struct {
    pthread_mutex_t mutex;              //Mutex para la sincronización
    pthread_cond_t cond;                 //Variable de condición para esperar estando en la barrera
    int count;                          //Almacena la cantidad de hilos que ya llegaron a la barrera
    int max_count;                      //Almacena la cantidad máxima de hilos que tienen que llegar a la barrera
} Barrier;

void barrier_init(Barrier* barrier, int max_count);             //Inicializa la barrera con un la catidad máxima de hilos
void barrier_wait(Barrier* barrier);                            //Espera hasta que todos los hilos lleguen a la barrera
void barrier_destroy(Barrier* barrier);                           //Destruye recursos

#endif // BARRIER_H


/*
Nota: Compilar la biblioteca con:
ar rcs libsync.a semaphore.o barrier.o monitor.o            (Si se quiere hacer estática)


*/