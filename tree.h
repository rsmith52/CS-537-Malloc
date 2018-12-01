// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
/* Include Guards ^^^ */
/* Prototypes for Variables */

typedef struct TreeNode TreeNode;

struct TreeNode {
	void * data;
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

Tree * createTree(void * data);

int addToTree(Tree * tree, void * data);

TreeNode * removeFromTree(Tree * tree, void * data);

void rotateLeft(Tree * tree, TreeNode * root, TreeNode * node);

void rotateRight(Tree * tree, TreeNode * root, TreeNode * node);

void fixViolation(Tree * tree, TreeNode * root, TreeNode * node);

void printTree(Tree * tree);

void printTreeHelper(Tree * tree, TreeNode * node);

#endif
