# - = Tarea #2 - BibliotecaSync = -

Biblioteca que permite facilitar el uso de Sincronización de hilos con Mutex y operadores Wait/Notify

## Tabla de Contenidos
- [PreRequisitos](#prerequisites)
- [Instalación](#installation)
- [Usos](#usage) 

## Prerequsitos
- GCC ver. 13.1
- Se recomienda el uso de Fedora Workstation 39

## Instalación
1. Descargar el release más reciente de la biblioteca o bien es posible descargar desde el repositorio por medio de GitBash siguiendo los siguientes comandos: 

- git clone https://github.com/RonaldoVindas/Tarea2-BibliotecaSync.git
- cd Tarea2-BibliotecaSync


2. Coloque los archivos en la misma ubicación que su programa

## Uso

Para hacer uso de está biblioteca debe seguir los siguientes pasos al crear un programa en el Lenguaje C:

1. Preferiblemente, ingrese el archivo de la biblioteca en la misma ubicación de su programa a realizar.
2. Al inicio de su programa en C incluya la siguiente línea de código:
   - #include “ubicación_del_archivo/BibliotecaSync.h”
3. Al momento de compilar su programa, asegúrese de enlazar la Biblioteca a su archivo durante la compilación siguiendo la estructura del siguiente comando al compilar:
   - gcc -o miPrograma miPrograma.c -lsync 
  
