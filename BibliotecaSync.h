//Plantilla de Header de la BibliotecaSync


#ifndef _MYLIB_H_
#define _MYLIB_H_

// a constant definition exported by library:
#define MAX_FOO  20

// a type definition exported by library:
struct foo_struct {
    int x;
    float y;
};

// a global variable exported by library
// "extern" means that this is not a variable declaration,
// but it defines that a variable named total_times of type
// int exists in the library implementation and is available
// for use by programs using the library.
// It is unusual for a library to export global variables
// to its users, but if it does, it is important that
// extern appears in the definition in the .h file
//extern int total_times;

//void Monitor(){}


//void Semaphore(){}


//void Barrier(){}




// a function prototype for a function exported by library:
// extern means that this function definition exists
// somewhere else.
/*
 * This function returns the larger of two float values
 *  y, z: the two values
 *  returns the value of the larger one
 */
//extern float bigger(float y, float z);

#endif

