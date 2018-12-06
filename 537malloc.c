// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "537malloc.h"

Tree * tree = NULL;

void * malloc537(size_t size) {

	if (size == 0) {
		// Size 0 malloced, which is weird
		fprintf(stderr, "Malloced size of 0, which is weird.\n");
	} 
	
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
	if (ptr == NULL) {
		int * pt = malloc537(size);
		return (void *) pt;
	}

	if (size == 0) {
		free537(ptr);
		return NULL;
	}

	if (tree == NULL) {
		fprintf(stderr, "Nothing has been malloced.\n");
		exit(-1);
	}

	Tuple *search = malloc(sizeof(struct Tuple));
	search = BSByValueWithinLen(ptr)->data;
	
	deleteNodeByValue(tree, search->addr);

	int *pt = realloc(ptr, size);

	Tuple *tuple = malloc(sizeof(struct Tuple));
	tuple->addr = (uintptr_t) &(*pt);
	tuple->len = size;

	addToTree(tree, tuple);
	printTree(tree);	

	return (void *) pt;
}

void memcheck537(void * ptr, size_t size) {
	if (ptr == NULL) {
		return NULL;
	}

	Tuple *search = malloc(sizeof(Tuple));
	search = BSByValue(tree, ptr)->data;

	if (search->len < size) {
		fprintf(stderr, "Detailed and informative error message\n");
		exit(-1);
	}
}
