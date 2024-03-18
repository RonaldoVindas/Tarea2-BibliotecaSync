#include <stdio.h>
#include <pthread.h>
#include "C:\Users\XPC\Desktop\Tarea2-BibliotecaSync\BibliotecaSync.h" 

#define NUM_THREADS 5

// Estructura para pasar argumentos a los hilos
typedef struct {
    int id;
    Monitor* monitor;
} ThreadArgs;

Monitor monitor;
int contador = 0;

void* thread_function(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;

    monitor_enter(args->monitor);
    while (contador + 1 != args->id) {
        monitor_wait(args->monitor);
    }
    printf("Hilo %d en la sección crítica\n", args->id);
    contador++;
    monitor_notify(args->monitor);
    monitor_exit(args->monitor);
    return NULL;
}


int main() {
    pthread_t threads[NUM_THREADS];
    ThreadArgs thread_args[NUM_THREADS];
    Monitor monitor;
    monitor_init(&monitor); 
    contador = 0; 
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
