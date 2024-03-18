#include "monitor.h"

void monitor_init(Monitor *monitor) {
    pthread_mutex_init(&(monitor->mutex), NULL);
    pthread_cond_init(&(monitor->cond_var), NULL);
}

void monitor_enter(Monitor *monitor) {
    pthread_mutex_lock(&(monitor->mutex));
}

void monitor_exit(Monitor *monitor) {
    pthread_mutex_unlock(&(monitor->mutex));
}

void monitor_wait(Monitor *monitor) {
    pthread_cond_wait(&(monitor->cond_var), &(monitor->mutex));
}

void monitor_notify(Monitor *monitor) {
    pthread_cond_signal(&(monitor->cond_var));
}

void monitor_destroy(Monitor *monitor) {
    pthread_mutex_destroy(&(monitor->mutex)); // Liberar el mutex
    pthread_cond_destroy(&(monitor->cond_var)); // Liberar la variable de condición
}