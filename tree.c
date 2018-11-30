// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include <stdlib.h>

#include "537malloc.h"
#include "tree.h"

Tree * createTree(void * data) {
	TreeNode * root = malloc(sizeof(TreeNode));
	root->data = data;
	root->color = 'b';
	root->parent = NULL;
	root->leftChild = NULL;
	root->rightChild = NULL;

	Tree * tree = malloc(sizeof(Tree));
	tree->root = root;
	tree->size = 1;

	return tree;
}

int addToTree(Tree * tree, void * data) {
	
	return -1;
}

TreeNode * removeFromTree(Tree * tree, void * data) {

	return NULL;
}

void printTree(Tree * tree) {
	if (tree->root->leftChild != NULL) {
		printTreeHelper(tree, tree->root->leftChild);
	}
	Tuple * data = tree->root->data;
	printf("%d is a %c node\n", data->addr, tree->root->color);	
	if (tree->root->rightChild != NULL) {
		printTreeHelper(tree, tree->root->rightChild);
	}
}

void printTreeHelper(Tree * tree, TreeNode * node) {
	if (node->leftChild != NULL) {
		printTreeHelper(tree, node->leftChild);
	}
	Tuple * data = tree->root->data;
	printf("%d is a %c node\n", data->addr, node->color);
	if (node->rightChild != NULL) {
		printTreeHelper(tree, node->rightChild);
	}
}
