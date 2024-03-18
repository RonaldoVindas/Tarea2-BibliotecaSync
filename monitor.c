/*Un monitor es una estructura de sincronización utilizada en programación concurrente para controlar el acceso a recursos compartidos por varios hilos o procesos. Proporciona un mecanismo para garantizar la exclusión mutua y la sincronización entre los hilos que comparten los recursos.
En otras palabras, permite a los hilos adquirir y liberar recursos compartidos de manera segura y coordinada, evitando condiciones de carrera y asegurando la coherencia de los datos compartidos.
La implementación básica de un monitor incluye:
- Un mutex: Un mutex (o cerrojo) es utilizado para lograr la exclusión mutua. Garantiza que solo un hilo pueda acceder al monitor o a los recursos protegidos por el monitor a la vez. Esto evita que múltiples hilos accedan simultáneamente a los recursos compartidos y protege contra condiciones de carrera.
- Variables de condición: Las variables de condición permiten a los hilos esperar y ser notificados sobre eventos específicos. Los hilos pueden esperar en una variable de condición hasta que se cumpla una cierta condición, y pueden ser notificados por otros hilos cuando se produce un cambio en la condición.
- Operaciones fundamentales: Las operaciones básicas que se pueden realizar en un monitor incluyen entrar y salir del monitor, esperar en una condición y notificar a otros hilos sobre cambios en la condición. Estas operaciones son necesarias para la coordinación entre los hilos que comparten los recursos protegidos por el monitor.
*/

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
    pthread_mutex_destroy(&(monitor->mutex)); 
    pthread_cond_destroy(&(monitor->cond_var)); 
}