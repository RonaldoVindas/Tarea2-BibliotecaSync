#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    int value;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} Semaphore;

Semaphore* createSemaphore(int initialValue) {
    Semaphore* semaphore = (Semaphore*)malloc(sizeof(Semaphore));
    if (semaphore == NULL) {
        perror("Error al crear el semáforo");
        exit(EXIT_FAILURE);
    }
    semaphore->value = initialValue;
    pthread_mutex_init(&(semaphore->mutex), NULL);
    pthread_cond_init(&(semaphore->cond), NULL);
    return semaphore;
}

void destroySemaphore(Semaphore* semaphore) {
    pthread_mutex_destroy(&(semaphore->mutex));
    pthread_cond_destroy(&(semaphore->cond));
    free(semaphore);
}

void waitSemaphore(Semaphore* semaphore) {
    pthread_mutex_lock(&(semaphore->mutex));
    while (semaphore->value <= 0) {
        pthread_cond_wait(&(semaphore->cond), &(semaphore->mutex));
    }
    semaphore->value--;
    pthread_mutex_unlock(&(semaphore->mutex));
}

void signalSemaphore(Semaphore* semaphore) {
    pthread_mutex_lock(&(semaphore->mutex));
    semaphore->value++;
    pthread_cond_signal(&(semaphore->cond));
    pthread_mutex_unlock(&(semaphore->mutex));
}

#define NUM_THREADS 5

Semaphore* semaphore;

void* thread_function(void* arg) {
    printf("Hilo %ld esperando en el semáforo\n", pthread_self());
    waitSemaphore(semaphore);
    printf("Hilo %ld liberado del semáforo\n", pthread_self());
    return NULL;
}

int main() {
    semaphore = createSemaphore(1);
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        
    }
}