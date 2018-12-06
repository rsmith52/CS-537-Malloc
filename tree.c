// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#include <stdlib.h>

#include "537malloc.h"
#include "tree.h"

Tree * createTree() {
	Tree * tree = malloc(sizeof(Tree));
	tree->root = NULL;

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

void addToTree(Tree * tree, Tuple * data) {
	
	// Create new TreeNode for insertion
	TreeNode * newNode = malloc(sizeof(struct TreeNode));
	newNode->data = data;
	newNode->color = 'r';
	newNode->free = 0;
	newNode->parent = NULL;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	// Do regular Binary Tree Insertion
	tree->root = BSTInsert(tree->root, newNode);
	
	// Maintain Red-Black Tree Properties
	fixViolation(tree, newNode);
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
					RotateLeft(tree, parent);
					node = parent;
					parent = node->parent;
				}
				// Case: node is left child of its parent
				// Right Rotation is needed
				RotateRight(tree, grandParent);
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
					RotateRight(tree, parent);
					node = parent;
					parent = node->parent;
				}
				// Case: node is right child of its parent
				// Left Rotation is needed
				RotateLeft(tree, grandParent);
				char tempColor = parent->color;
				parent->color = grandParent->color;
				grandParent->color = tempColor;
				node = parent;
			}
		}
	}	
	tree->root->color = 'b';	
}

void RotateLeft(Tree * tree, TreeNode * node) {
	TreeNode * newParent = node->rightChild;
	if (node == tree->root) {
		tree->root = newParent;
	}
	// Move Node down
	if (node->parent != NULL) {
		// If is left child of its parent
		if (node->parent->leftChild == node) {
			node->parent->leftChild = newParent;
		} else {
			node->parent->rightChild = newParent;
		}
	}
	newParent->parent = node->parent;
	node->parent = newParent;

	node->rightChild = newParent->leftChild;
	if (newParent->leftChild != NULL) {
		newParent->leftChild->parent = node;
	}
	newParent->leftChild = node;
}

void RotateRight(Tree * tree, TreeNode * node) {
	TreeNode * newParent = node->leftChild;
	if (node == tree->root) {
		tree->root = newParent;
	}
	// Move Node down
	if (node->parent != NULL) {
		// If it is the left child of its parent
		if (node->parent->leftChild == node) {
			node->parent->leftChild = newParent;
		} else {
			node->parent->rightChild = newParent;
		}
	}
	newParent->parent = node->parent;
	node->parent = newParent;

	node->leftChild = newParent->rightChild;
	if (newParent->rightChild != NULL) {
		newParent->rightChild->parent = node;
	}
	newParent->rightChild = node;
}

TreeNode * getNoLeftChildNode(TreeNode * node) {
	TreeNode * temp = node;
	while (temp->leftChild != NULL) {
		temp = temp->leftChild;
	}
	return temp;
}

TreeNode * getSibling(TreeNode * node) {
	if (node->parent == NULL) {
		return NULL;
	}
	if (node->parent->leftChild == node) {
		return node->parent->rightChild;
	} else {
		return node->parent->leftChild;
	}
}

int hasRedChild(TreeNode * node) {
	if (node->leftChild != NULL) {
		if (node->leftChild->color == 'r') {
			return 1;
		}
	} else if (node->rightChild != NULL) {
		if (node->rightChild->color == 'r') {
			return 1;
		}
	}
	return 0;
}

int leftChildRed(TreeNode * node) {
	if (node->leftChild != NULL) {
		if (node->leftChild->color == 'r') {
			return 1;
		}
	}
	return 0;
}

TreeNode * BSTReplace(TreeNode * node) {
	// 2 Children
	if (node->leftChild != NULL && node->rightChild != NULL) {
		return getNoLeftChildNode(node->rightChild);
	}

	// Is Leaf
	if (node->leftChild == NULL && node->rightChild == NULL) {
		return NULL;
	}

	// Single Child
	if (node->leftChild != NULL) {
		return node->leftChild;
	} else {
		return node->rightChild;
	}
}

void deleteNode(Tree * tree, TreeNode * node) {
	TreeNode * node2 = BSTReplace(node);
	if (node2 == node) {
		node2 = NULL;
	}

	int nodesBothBlack;
	if ((node2 == NULL || node2->color == 'b') && (node->color == 'b')) {
		nodesBothBlack = 1;
	} else {
		nodesBothBlack = 0;
	}

	TreeNode * parent = node->parent;

	if (node2 == NULL) {
		if (node == tree->root) {
			tree->root = NULL;
		} else {
			if (nodesBothBlack) {
				fixDoubleBlack(tree, node);
			} else {
				if (getSibling(node) != NULL) {
					getSibling(node)->color = 'r';
				}
			}
			if (node->parent != NULL) {
				if (node->parent->leftChild == node) {
					parent->leftChild = NULL;
				} else {
					parent->rightChild = NULL;
				}
			}
		}
		free(node);
		node = NULL;
		return;
	}
	if (node->leftChild == NULL || node->rightChild == NULL) {
		if (node == tree->root) {
			node->data = node2->data;
			node->leftChild = NULL;
			node->rightChild = NULL;
			free(node2);
			node2 = NULL;
		} else {
			if (node->parent->leftChild == node) {
				parent->leftChild = node2;
			} else  {
				parent->rightChild = node2;
			}
			free(node);
			node = NULL;
			node2->parent = parent;
			if (nodesBothBlack) {
				fixDoubleBlack(tree, node2);
			} else {
				node2->color = 'b';
			}
		}
		return;
	}
	Tuple * temp = node->data;
	node->data = node2->data;
	node2->data = temp;
	deleteNode(tree, node2);
}

void fixDoubleBlack(Tree * tree, TreeNode * node) {
	// Reached root and done
	if (node == tree->root) {
		return;
	}
	TreeNode * sibling = getSibling(node);
	TreeNode * parent = node->parent;
	if (sibling == NULL) {
		fixDoubleBlack(tree, parent);
	} else {
		if (sibling->color == 'r') {
			parent->color = 'r';
			sibling->color = 'b';
			if (node->parent->leftChild == node) {
				RotateRight(tree, parent);
			} else {
				RotateLeft(tree, parent);
			}
			fixDoubleBlack(tree, parent);
		} else {
			if (hasRedChild(sibling)) {
				if (leftChildRed(sibling)) {
					if (sibling->parent->leftChild == sibling) {
						sibling->leftChild->color = sibling->color;
						sibling->color = parent->color;
						RotateRight(tree, parent);
					} else {
						sibling->leftChild->color = parent->color;
						RotateRight(tree, sibling);
						RotateLeft(tree, parent);
					}
				} else {
					if (sibling->parent->leftChild == sibling) {
						sibling->rightChild->color = parent->color;
						RotateLeft(tree, sibling);
						RotateRight(tree, parent);
					} else {
						sibling->rightChild->color = sibling->color;
						sibling->color = parent->color;
						RotateLeft(tree, parent);
					}
				}
				parent->color = 'b';
			} else {
				sibling->color = 'r';
				if (parent->color == 'b') {
					fixDoubleBlack(tree, parent);
				} else {
					parent->color = 'b';
				}
			}
		}
	}

}

TreeNode * BSByValueWithinLen(Tree * tree, uintptr_t value) {
	TreeNode * temp = tree->root;

	while (temp != NULL) {
		if (value < temp->data->addr) {
			if (temp->leftChild == NULL) {
				return NULL;
			} else {
				temp = temp->leftChild;
			}
		} else if (value <= temp->data->addr + temp->data->len) {
			break;
		} else {
			if (temp->rightChild == NULL) {
				return NULL;
			} else {
				temp = temp->rightChild;
			}
		}
	}
	return temp;
}

TreeNode * BSByValue(Tree * tree, uintptr_t value) {
	if (tree == NULL) {
		return NULL;
	}
	TreeNode * temp = tree->root;
	while (temp != NULL) {
		if (value < temp->data->addr) {
			if (temp->leftChild == NULL) {
				return NULL;
			} else {
				temp = temp->leftChild;
			}
		} else if (value == temp->data->addr) {
			break;
		} else {
			if (temp->rightChild == NULL) {
				return NULL;
			} else {
				temp = temp->rightChild;
			}
		}
	}
	return temp;
}

Tuple * deleteNodeByValue(Tree * tree, uintptr_t value) {
	if (tree->root == NULL) {
		return NULL;
	}
	TreeNode * matchingNode = BSByValue(tree, value);
	if (matchingNode == NULL) {
		fprintf(stderr, "No node with that value found to delete\n");
		return NULL;
	}
	Tuple * removedNode = matchingNode->data;
	deleteNode(tree, matchingNode);
	return removedNode;
}

void printTree(Tree * tree) {
	if (tree->root == NULL) {
		printf("Empty Tree\n");
	} else {
		if (tree->root->leftChild != NULL) {
			printTreeHelper(tree->root->leftChild);
		}
		printf("%ld is a %c root node\n", tree->root->data->addr, tree->root->color);	
		if (tree->root->rightChild != NULL) {
			printTreeHelper(tree->root->rightChild);
		}
	}
	printf("\n");
}

void printTreeHelper(TreeNode * node) {
	if (node->leftChild != NULL) {
		printTreeHelper(node->leftChild);
	}
	printf("%ld is a %c node\n", node->data->addr, node->color);
	if (node->rightChild != NULL) {
		printTreeHelper(node->rightChild);
	}
}
