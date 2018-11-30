// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
/* Include Guards ^^^ */
/* Prototypes for Variables */

typedef struct TreeNodes {
	void * data;
	char color;
	struct TreeNode * parent;
	struct TreeNode * leftChild;
	struct TreeNode * rightChild;
} TreeNode;


typedef struct Trees {
	TreeNode * root;
	int size;
} Tree;

/* Prototypes for Functions */

Tree * createTree(void * data);

int addToTree(Tree * tree, void * data);

TreeNode * removeFromTree(Tree * tree, void * data);

void rotateLeft(Tree * tree, TreeNode * topNode, TreeNode * node);

void rotateRight(Tree * tree, TreeNode * topNode, TreeNode * node);

void printTree(Tree * tree);

void printTreeHelper(Tree * tree, TreeNode * node);

#endif
