// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include <stdint.h>
#include "537malloc.h"
#include "tree.h"

int main () {

	printf("Hello World!\n");	
	
	int * test = malloc537(sizeof(int));
	int ** test2 = malloc537(sizeof(int *));
	char * test3 = malloc537(sizeof(char) * 20);

	realloc537(test3, sizeof(char) * 40);

	/*
	free537(test);
	free537(test2);
	free537(test3);
	*/
	return -1;
}
