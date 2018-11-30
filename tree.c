// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include <stdlib.h>

#include "tree.h"

Tree * createTree() {
	TreeNode * root = malloc(sizeof(TreeNode));
	root->leftChild = NULL;
	root->rightChild = NULL;

	Tree * tree = malloc(sizeof(Tree));
	tree->root = root;

	return tree;
}

int addToTree(void * data) {
	
	return -1;
}

TreeNode * removeFromTree(void * data) {

	return NULL;
}
