#ifndef MONITOR_H
#define MONITOR_H

typedef struct {
    int occupied;
    int wait_count;
    int signal_count;
} Monitor;

void monitor_init(Monitor *monitor);
void monitor_enter(Monitor *monitor);
void monitor_exit(Monitor *monitor);

#endif /* MONITOR_H */


