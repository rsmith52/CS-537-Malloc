// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
/* Include Guards ^^^ */
/* Prototypes for Variables */

typedef struct TreeNodes {
	int data;
	char color;
	void *  parent;
	void * children;
} TreeNode;


typedef struct Trees {
	TreeNode * tempDataList;
} Tree;

/* Prototypes for Functions */

Tree * createTree();

int addToTree(int data);

int removeFromTree(int data);

#endif
