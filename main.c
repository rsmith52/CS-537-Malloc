// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include <stdint.h>
#include "537malloc.h"
#include "tree.h"

int main () {

	printf("Hello World!\n");	
	Tree * tree = createTree();

	Tuple ** tuples = malloc(sizeof(Tuple*) * 50);
	for (int i = 0; i < 50; i++) {
		tuples[i] = malloc(sizeof(Tuple));
		tuples[i]->len = 0;
	}

	tuples[0]->addr = 0;
	tuples[1]->addr = 1;
	tuples[2]->addr = 2;
	tuples[3]->addr = 3;
	tuples[4]->addr = 4;
	tuples[5]->addr = 5;
	tuples[6]->addr = 6;
	tuples[7]->addr = 7;
	tuples[8]->addr = 8;
	tuples[9]->addr = 9;
	tuples[10]->addr = 10;

	addToTree(tree, tuples[1]);
	printTree(tree);
	addToTree(tree, tuples[0]);
	printTree(tree);
	addToTree(tree, tuples[2]);
	printTree(tree);
	addToTree(tree, tuples[3]);
	printTree(tree);
	addToTree(tree, tuples[4]);
	printTree(tree);
	
	deleteNodeByValue(tree, 0);
	printTree(tree);
	
	deleteNodeByValue(tree, 1);
	printTree(tree);

	return -1;
}
