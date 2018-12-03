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

void addToTree(Tree * tree, Tuple * data);

void fixViolation(Tree * tree, TreeNode * node);

void removeRotateLeft(Tree * tree, TreeNode * node);

void removeRotateRight(Tree * tree, TreeNode * node);

TreeNode * getNoLeftChildNode(TreeNode * node);

TreeNode * getSibling(TreeNode * node);

int hasRedChild(TreeNode * node);

int leftChildRed(TreeNode * node);

TreeNode * BSTReplace(TreeNode * node);

void deleteNode(Tree * tree, TreeNode * node);

void fixDoubleBlack(Tree * tree, TreeNode * node);

TreeNode * BSByValue(Tree * tree, Tuple * value);

void deleteByValue(Tree * tree, Tuple * value);

void printTree(Tree * tree);

void printTreeHelper(TreeNode * node);

#endif
