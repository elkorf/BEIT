/*
 * BinTree.h
 *
 *  Created on: 22-Jan-2019
 *      Author: g-1123347
 */

#ifndef BINTREE_H_
#define BINTREE_H_

struct node{
	int data;
	node *left,*right;
};
class BinTree{
	node *root;
public:
	BinTree();
	void displayTree(node *);
	node *getNode(int);
	node *retRoot();
	int findDepth(node *);
	void leafNodes(node *);
	int leafCount(node *);
	node* copyTree(node *);
	void insertNode(int);
	void preTraverse(node *);
	void inTraverse(node *);
	void postTraverse(node *);
	virtual ~BinTree();
};

#endif /* BINTREE_H_ */
