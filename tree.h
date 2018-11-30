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
	TreeNode * DataList;
} Tree;

/* Prototypes for Functions */

Tree * createTree();

int addToTree(void * data);

TreeNode * removeFromTree(void * data);

#endif
