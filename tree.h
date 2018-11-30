// Ray Smith - rsmith52 - rays - Nate Hoffman - nhoffman5 -nhoffman
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
/* Include Guards ^^^ */
/* Prototypes for Variables */

typedef struct TreeNodes {
	int data;
	char color;
	TreeNode parent;
	TreeNode leftChild;
	TreeNode rightChild;
} TreeNode;


typedef struct Trees {
	TreeNode root;
	TreeNode* tempDataList;
} Tree;

/* Prototypes for Functions */

Tree * createTree();

int addToTree(int data);

TreeNode *removeFromTree(int data);

#endif
