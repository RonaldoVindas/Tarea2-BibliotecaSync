/*
Instituto Tecnológico de Costa Rica | Ing. Computación | Semestre 1 - 2024

Sistemas Operativos - Tarea #2

Elaborado Por:
Adrián Herrera
Rebeca Madrigal
Ronaldo Vindas

*/

#include "barrier.h"


void barrier_init(Barrier* barrier, int max_count) {
    /*
    Funnción que innicializa la barrera.
    Entradas: barrier->puntero a la barrera,  max_count->cantidad máxima "n" de hilos
    Salidas: N/A, Barrera Inicializada
    Restricciones: N/A
    */
    barrier->max_count = max_count;
    barrier->count = 0;
    pthread_mutex_init(&barrier->mutex, NULL);                          //Inicia el mutex
    pthread_cond_init(&barrier->cond, NULL);                            //Inicia la variable de condición
}

void barrier_wait(Barrier* barrier) {
    /*
    Funnción que bloquea a los hilos en la barrera.
    Entradas: barrier->puntero a la barrera
    Salidas: N/A
    Restricciones: N/A
    */

    pthread_mutex_lock(&barrier->mutex);                        //Se bloquea el mutex para evitar que ocurra una condición de carrera
    barrier->count++;                                           //Incrementa la cantidad de hilos en espera
    if (barrier->count < barrier->max_count) {                   //No se van a soltar los hilos hasta que todos los hilos hayan llegado a la barrera
        pthread_cond_wait(&barrier->cond, &barrier->mutex);      //Espera la condición de la barrera
    } else {
        barrier->count = 0;                                     //Se quiere reiniciar el contador de hilos por si luego se quiere vovler a usar la barrera
        pthread_cond_broadcast(&barrier->cond);                 //Se despiertan todos los hilos
    }
    pthread_mutex_unlock(&barrier->mutex);                  //Libera la exlución mutua
}

void barrier_destroy(Barrier* barrier) {
    /*
    Funnción que destruye la barrera.
    Entradas: barrier->puntero a la barrera
    Salidas: Recursos liberados.
    Restricciones: N/A
    */
    pthread_mutex_destroy(&barrier->mutex);         //Elimina el Mutex
    pthread_cond_destroy(&barrier->cond);           //Elimina la condición de barrera
}


/*
Nota: Compilar con 

gcc -c barrier.c -o barrier.o
*/
