// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include "537malloc.h"
#include "tree.h"

int main () {

	printf("Hello World!\n");

	Tuple * data = malloc(sizeof(Tuple));
	data->addr = 3;
	data->len = 0;
	
	Tree * tree = createTree(data);
	printTree(tree);
	printf("\n");

	Tuple * data2 = malloc(sizeof(Tuple));
	data2->addr = 1;
	data2->len = 0;

	addToTree(tree, data2);
	printTree(tree);
	printf("\n");

	Tuple * data3 = malloc(sizeof(Tuple));
	data3->addr = 5;
	data3->len = 0;

	addToTree(tree, data3);
	printTree(tree);
	printf("\n");

	Tuple * data4 = malloc(sizeof(Tuple));
	data4->addr = 7;
	data4->len = 0;

	addToTree(tree, data4);
	printTree(tree);	


	return -1;
}
