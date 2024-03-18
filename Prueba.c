#include <stdio.h>
#include <pthread.h>
#include "C:\Users\XPC\Desktop\Tarea2-BibliotecaSync\BibliotecaSync.h" // Incluye el archivo de encabezado de la biblioteca que contiene todas las estructuras de sincronización

#define NUM_THREADS 5

// Estructura para pasar argumentos a los hilos
typedef struct {
    int id;
    Barrier* barrier;
} ThreadArgs;

// Función que ejecutarán los hilos
void* thread_function(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    printf("Hilo %d llegando a la barrera\n", args->id);
    barrier_wait(args->barrier); // Espera en la barrera
    printf("Hilo %d liberado de la barrera\n", args->id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadArgs thread_args[NUM_THREADS];
    Barrier barrier;

    barrier_init(&barrier, NUM_THREADS); // Inicializa la barrera con el número de hilos

    // Crea y ejecuta los hilos
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].id = i + 1;
        thread_args[i].barrier = &barrier;
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_args[i]);
    }

    // Espera a que todos los hilos terminen
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    barrier_destroy(&barrier); // Destruye la barrera al finalizar

    return 0;
}