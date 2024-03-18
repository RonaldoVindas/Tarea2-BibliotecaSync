#ifndef MONITOR_H
#define MONITOR_H

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
    pthread_mutex_t mutex;
    pthread_cond_t cond_var;
} Monitor;

void monitor_init(Monitor *monitor);
void monitor_enter(Monitor *monitor);
void monitor_exit(Monitor *monitor);
void monitor_wait(Monitor *monitor);
void monitor_notify(Monitor *monitor);
void monitor_destroy(Monitor *monitor);
#endif /* MONITOR_H */

