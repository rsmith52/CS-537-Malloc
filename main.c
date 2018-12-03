// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include "537malloc.h"
#include "tree.h"

int main () {

	printf("Hello World!\n");	
	Tree * tree = createTree();

	Tuple ** tuples = malloc(sizeof(Tuple*) * 50);
	for (int i = 0; i < 50; i++) {
		tuples[i] = malloc(sizeof(Tuple));
		tuples[i]->addr = i;
		tuples[i]->len = 0;
		addToTree(tree, tuples[i]);
		printTree(tree);
		printf("\n");
	}

	return -1;
}
