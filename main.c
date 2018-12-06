// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include <stdint.h>
#include "537malloc.h"
#include "tree.h"

int main () {

	printf("Hello World!\n");	
	
	int * test = malloc537(sizeof(int));
	int ** test2 = malloc537(sizeof(int *));
	char * test3 = malloc537(sizeof(char) * 20);

	char * test4 = realloc537(test3, sizeof(char) * 40);

	printf("test 3 after realloc\n");
	memcheck537(test3, 0);

	int * ptr = NULL;
	free537(ptr);
	/*
	free537(test);
	free537(test2);
	free537(test3);
	*/

	printf("Goodbye World!\n");
	return -1;
}
