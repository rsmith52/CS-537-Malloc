// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#ifndef MALLOC_H_INCLUDED
#define MALLOC_H_INCLUDED
/* Include Guards ^^^ */
#include <stdlib.h>
#include <stdio.h>
/* Prototypes for Variables */

typedef struct Tuples {
	int addr;
	size_t len;
} Tuple;

/* Prototypes for Functions */

void * malloc537(size_t size);

void free537(void * ptr);

void * realloc537(void * ptr, size_t size);

void memcheck537(void * ptr, size_t size);

#endif
