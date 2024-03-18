#include <stdio.h>
#include <pthread.h>
#include "C:\Users\XPC\Desktop\Tarea2-BibliotecaSync\BibliotecaSync.h" // Incluye el archivo de encabezado de la biblioteca que contiene todas las estructuras de sincronización

#define NUM_THREADS 5

// Estructura para pasar argumentos a los hilos
typedef struct {
    int id;
    Monitor* monitor;
} ThreadArgs;

// Función que ejecutarán los hilos
void* thread_function(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    monitor_enter(args->monitor);
    printf("Hilo %d en la sección crítica\n", args->id);
    monitor_exit(args->monitor);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadArgs thread_args[NUM_THREADS];
    Monitor monitor;
    monitor_init(&monitor); 
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].id = i + 1;
        thread_args[i].monitor = &monitor;
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_args[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    monitor_destroy(&monitor); // Destruir el monitor al finalizar
    return 0;
}
