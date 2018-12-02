// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include <stdlib.h>

#include "537malloc.h"
#include "tree.h"

Tree * createTree() {
	Tree * tree = malloc(sizeof(Tree));
	tree->root = NULL;
	tree->size = 0;

	return tree;
}

void * BSTInsert(TreeNode * root, TreeNode * newNode) {
	if (root == NULL) {
		return newNode;
	}
	if (root->data->addr > newNode->data->addr) {
		if (root->leftChild != NULL) {
			root->leftChild = BSTInsert(root->leftChild, newNode);
		} else {
			root->leftChild = newNode;
			newNode->parent = root;
		}
	} else {
		if (root->rightChild != NULL) {
			root->rightChild = BSTInsert(root->rightChild, newNode);
		} else {
			root->rightChild = newNode;
			newNode->parent = root;
		}
	}
	return root;
}

void addToTree(Tree * tree, void * data) {
	
	// Create new TreeNode for insertion
	TreeNode * newNode = malloc(sizeof(struct TreeNode));
	newNode->data = data;
	newNode->color = 'r';
	newNode->parent = NULL;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	// Do regular Binary Tree Insertion
	tree->root = BSTInsert(tree->root, newNode);
	
	// Maintain Red-Black Tree Properties
	fixViolation(tree, newNode);

	// Update Tree Size	
	tree->size++;
}

TreeNode * removeFromTree(Tree * tree, void * data) {

	return NULL;
}

void rotateLeft(Tree * tree, TreeNode * data) {
	TreeNode * right = data->rightChild;

	data->rightChild = right->leftChild;

	if (data->rightChild != NULL) {
		data->rightChild->parent = data;
	}

	right->parent = data->parent;

	if (data->parent == NULL) {
		tree->root = right;
	} else if (data == data->parent->leftChild) {
		data->parent->leftChild = right;
	} else {
		data->parent->rightChild = right;
	}

	right->leftChild = data;
	data->parent = right;
}

void rotateRight(Tree * tree, TreeNode * data) {
	TreeNode *left = data->leftChild;

	data->leftChild = left->rightChild;

	if (data->leftChild != NULL) {
		data->leftChild->parent = data;
	}

	left->leftChild->parent = data->parent;

	if (data->parent == NULL) {
		tree->root = left;
	} else if (data == data->parent->leftChild) {
		data->parent->leftChild = left;
	} else {
		data->parent->rightChild = left;
	}

	left->rightChild = data;
	data->parent = left;
}

void fixViolation(Tree * tree, TreeNode * node) {
	TreeNode * parent = NULL;
	TreeNode * grandParent = NULL;

	while ((node != tree->root) && (node->color != 'b') && (node->parent->color == 'r')) {
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
					rotateLeft(tree, parent);
					node = parent;
					parent = node->parent;
				}
				// Case: node is left child of its parent
				// Right Rotation is needed
				rotateRight(tree, grandParent);
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
					rotateRight(tree, parent);
					node = parent;
					parent = node->parent;
				}
				// Case: node is right child of its parent
				// Left Rotation is needed
				rotateLeft(tree, grandParent);
				char tempColor = parent->color;
				parent->color = grandParent->color;
				grandParent->color = tempColor;
				node = parent;
			}
		}
	}	
	tree->root->color = 'b';	
}

void printTree(Tree * tree) {
	if (tree->root == NULL) {
		printf("Empty Tree\n");
	} else {
		if (tree->root->leftChild != NULL) {
			printTreeHelper(tree->root->leftChild);
		}	
		printf("%d is a %c root node\n", tree->root->data->addr, tree->root->color);	
		if (tree->root->rightChild != NULL) {
			printTreeHelper(tree->root->rightChild);
		}
	}
}

void printTreeHelper(TreeNode * node) {
	if (node->leftChild != NULL) {
		printTreeHelper(node->leftChild);
	}
	printf("%d is a %c node\n", node->data->addr, node->color);
	if (node->rightChild != NULL) {
		printTreeHelper(node->rightChild);
	}
}
