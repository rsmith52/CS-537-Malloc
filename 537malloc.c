// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "537malloc.h"

Tree * tree = NULL;
Tree * freeTree = NULL;

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

	return (void *) pt;
}

void free537(void * ptr) {

	printTree(tree);

	if (freeTree == NULL) {
		freeTree = createTree();
	}
	
	if (ptr == NULL) {
		fprintf(stderr, "Attempted to call free on NULL pointer, doing nothing.\n");
	} else {
		

		int * pt = (int*) ptr;
		uintptr_t searchAddr = (uintptr_t) &(*pt);

		if (BSByValue(tree, searchAddr) != NULL) {
			// PTR was malloced by malloc537, not yet freed
			// Remove from tree, add to freeTree
			// Free memory
			Tuple * removedTuple = deleteNodeByValue(tree, searchAddr);
			addToTree(freeTree, removedTuple);
			free(ptr);
		} else if (BSByValueWithinLen(tree, searchAddr) != NULL) {
			// Trying to free something malloced by malloc537, but not 1st byte
			fprintf(stderr, "Attempted to free memory with pointer that is not to the 1st byte of what was allocated.\n");
			exit(-1);
		} else if (BSByValue(freeTree, searchAddr) != NULL) {	
			// Trying to free something already freed by free537
			fprintf(stderr, "Attempted to free memory that was already freed.\n");
			exit(-1);
		} else if (BSByValueWithinLen(freeTree, searchAddr) != NULL) {
			// Trying to free something already freed by free537, but not 1st byte
			fprintf(stderr, "Attempted to free memory that was already freed, but also with pointer that is not to the 1st byte of was was allocated and freed.\n");
			exit(-1);
		} else {
			// Trying to free something never malloced by malloc537
			fprintf(stderr, "Attempted to free memory that was never allocated by malloc537.\n");
			exit(-1);
		}
	}
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

	int * ptr2 = (int *) ptr;
	uintptr_t searchAddr = (uintptr_t) &(*ptr2);
	
	Tuple * search = malloc(sizeof(Tuple));
	search = NULL;
	TreeNode * temp	= BSByValue(tree, searchAddr);
	if (temp != NULL) {
		search = temp->data;
	}

	if (search == NULL) {
		// Tried reallocing something not allocated by malloc537
		search = BSByValueWithinLen(tree, searchAddr)->data;
		if (search == NULL) {
			if (freeTree != NULL) {
				search = BSByValue(freeTree, searchAddr)->data;
				if (search != NULL) {
					// Tried reallocing something already freed
					fprintf(stderr, "Attempted to realloc memory that has already been freed.\n");
					exit(-1);
				} else {
					search = BSByValueWithinLen(freeTree, searchAddr)->data;
					if (search != NULL) {
						// Tried reallocing something already freed, but by pointer not to 1st byte
						fprintf(stderr, "Attempted to realloc memory that has already been freed, but not by pointer to 1st byte.\n");
						exit(-1);
					}
				}
					
			}
			// Tried reallocing something never allocated by malloc537
			fprintf(stderr, "Attempted to realloc memory never allocated by malloc537.\n");
			exit(-1);
		} else {
			// Tried reallocing something allocated by malloc537, but with pointer not to 1st byte
			fprintf(stderr, "Attempted to realloc memory allocated by malloc537, but not by pointer to 1st byte.\n");
			exit(-1);
		}
	}
	
	deleteNodeByValue(tree, search->addr);

	int * pt = realloc(ptr, size);

	Tuple *tuple = malloc(sizeof(Tuple));
	tuple->addr = (uintptr_t) &(*pt);
	tuple->len = size;

	addToTree(tree, tuple);

	return (void *) pt;
}

void memcheck537(void * ptr, size_t size) {
	if (ptr == NULL) {
		return;
	}

	int * ptr2 = (int *) ptr;
	uintptr_t searchAddr = (uintptr_t) &(*ptr2);
	uintptr_t endAddr = 0;

	Tuple * search = malloc(sizeof(Tuple));
	search = NULL;
	TreeNode * temp  = BSByValueWithinLen(tree, searchAddr);

	if (temp != NULL) {
		search = temp->data;
		endAddr = search->addr + search->len;
	}

	if (search == NULL) {
		fprintf(stderr, "Checked memory not fully allocated by malloc537.\n");
		exit(-1);
	} else if (search->len < size) {
		fprintf(stderr, "Checked memory not fully allocated by malloc537.\n");
		exit(-1);
	} else if (searchAddr + size > endAddr) {
		fprintf(stderr, "Checked memory not fully allocated by malloc537.\n");
		exit(-1);
	}
}
