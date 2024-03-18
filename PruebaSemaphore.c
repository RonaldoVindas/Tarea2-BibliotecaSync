#include <stdio.h>
#include <pthread.h>
#include "semaphore.h"
#include "semaphore.c"
#include <unistd.h>
#define NUM_THREADS 5


typedef struct {
    int id;
    Semaphore* semaphore;
} ThreadArgs;


void* thread_function(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    printf("Hilo %d esperando en el semáforo\n", args->id);
    waitSemaphore(args->semaphore); 
    printf("Hilo %d adquirió el semáforo\n", args->id);
    printf("Hilo %d realizando trabajo dentro de la sección crítica\n", args->id);
    sleep(1);
    signalSemaphore(args->semaphore); 
    printf("Hilo %d liberó el semáforo\n", args->id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadArgs thread_args[NUM_THREADS];
    Semaphore* semaphore = createSemaphore(2); 

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].id = i + 1;
        thread_args[i].semaphore = semaphore;
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_args[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    destroySemaphore(semaphore); 

    return 0;
}
