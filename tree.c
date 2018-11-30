// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

Tree *createTree(int data) {
	TreeNode *root = malloc(sizeof(TreeNode));
	root->leftChild = malloc(sizeof(TreeNode));
	root->data = data;
	
	Tree *tree = malloc(sizeof(Tree));
	tree->root = root;

	return tree;
}

int addToTree(int data) {
	return data;
}

int removeFromTree(int data) {
	return data;
}

void searchTree() {

}
