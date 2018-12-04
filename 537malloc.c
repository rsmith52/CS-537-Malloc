// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "537malloc.h"

Tree * tree = NULL;

void * malloc537(size_t size) {

	if (tree == NULL) {
		tree = createTree();
	}

	int * pt = malloc(size);
	Tuple * tuple = malloc(sizeof(Tuple));
	tuple->addr = (uintptr_t) &(*pt);
	tuple->len = size;

	addToTree(tree, tuple);
	printTree(tree);

	return (void *) pt;
}

void free537(void * ptr) {

}

void * realloc537(void * ptr, size_t size) {

	return NULL;
}

void memcheck537(void * ptr, size_t size) {

}
