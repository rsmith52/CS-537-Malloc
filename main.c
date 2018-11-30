// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include "537malloc.h"
#include "tree.h"

int main () {

	printf("Hello World!\n");

	Tuple * data = malloc(sizeof(Tuple));
	data->addr = 1;
	data->len = 0;	
	
	Tree * tree = createTree(data);

	printTree(tree);

	return -1;
}
