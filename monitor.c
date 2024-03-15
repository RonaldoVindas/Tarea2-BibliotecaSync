#include "monitor.h"
#include <unistd.h>

void monitor_init(Monitor *monitor) {
    monitor->occupied = 0;
    monitor->wait_count = 0;
    monitor->signal_count = 0;
}

void monitor_enter(Monitor *monitor) {
    while (1) {
        while (monitor->occupied) {
            monitor->wait_count++;
            sleep(1); // Simula una espera
        }

        if (monitor->wait_count > 0) {
            monitor->wait_count--;
        } else {
            monitor->occupied = 1;
            break;
        }
    }
}

void monitor_exit(Monitor *monitor) {
    monitor->occupied = 0;
    if (monitor->wait_count > 0) {
        monitor->signal_count++;
    }
}
