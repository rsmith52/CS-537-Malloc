// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include <stdlib.h>

#include "537malloc.h"
#include "tree.h"

Tree * createTree(void * data) {
	TreeNode * root = malloc(sizeof(struct TreeNode));
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

void rotateLeft(Tree * tree, TreeNode * root, TreeNode * node) {

}

void rotateRight(Tree * tree, TreeNode * root, TreeNode * node) {

}

void fixViolation(Tree * tree, TreeNode * root, TreeNode * node) {
	TreeNode * parent = NULL;
	TreeNode * grandParent = NULL;

	while ((node != root) && (node->color != 'b') && (node->parent->color == 'r')) {
		parent = node->parent;
		grandParent = parent->parent;

		// Case: Parent of node is left child of grand-parent of node
		if (parent == grandParent->leftChild) {
			TreeNode * uncle = grandParent->rightChild;
			// Case: The uncle of node is also red
			// Only recolor is needed
			if (uncle != NULL && uncle->color == 'r') {
				grandParent->color = 'r';
				parent->color = 'b';
				uncle->color = 'b';
				node = grandParent;
			} else {
				// Case: node is right child of its parent
				// Left Rotation is needed
				if (node == parent->rightChild) {
					rotateLeft(tree, root, parent);
					node = parent;
					parent = node->parent;
				}
				// Case: node is left child of its parent
				// Right Rotation is needed
				rotateRight(tree, root, grandParent);
				char tempColor = parent->color;
				parent->color = grandParent->color;
				grandParent->color = tempColor;
				node = parent;
			}
		}
		// Case: Parent of node is right child of grand-parent of node
		else {
			TreeNode * uncle = grandParent->leftChild;
			// Case: The uncle of node is also red
			// Only recolor is needed
			if (uncle != NULL && uncle->color == 'r') {
				grandParent->color = 'r';
				parent->color = 'b';
				uncle->color = 'b';
				node = grandParent;
			} else {
				// Case: node is left child of its parent
				// Right Rotation is needed
				if (node == parent->leftChild) {
					rotateRight(tree, root, parent);
					node = parent;
					parent = node->parent;
				}
				// Case: node is right child of its parent
				// Left Rotation is needed
				rotateLeft(tree, root, grandParent);
				char tempColor = parent->color;
				parent->color = grandParent->color;
				grandParent->color = tempColor;
				node = parent;
			}
		}
	}	
	root->color = 'b';	
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
