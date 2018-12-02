// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
/* Include Guards ^^^ */
#include <stdlib.h>
#include <stdio.h>
/* Prototypes for Variables */

typedef struct Tuples {
        int addr;
        size_t len;
} Tuple;

typedef struct TreeNode TreeNode;

struct TreeNode {
	Tuple * data;
	char color;
	TreeNode * parent;
	TreeNode * leftChild;
	TreeNode * rightChild;
};

typedef struct Trees {
	TreeNode * root;
	int size;
} Tree;

/* Prototypes for Functions */

Tree * createTree();

void * BSTInsert(TreeNode * root, TreeNode * newNode);

void addToTree(Tree * tree, void * data);

TreeNode * removeFromTree(Tree * tree, void * data);

void rotateLeft(Tree * tree, TreeNode * data);

void rotateRight(Tree * tree, TreeNode * data);

void fixViolation(Tree * tree, TreeNode * node);

void printTree(Tree * tree);

void printTreeHelper(TreeNode * node);

#endif
