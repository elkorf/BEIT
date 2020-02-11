/*
 * BinTree.h
 *
 *  Created on: 22-Jan-2019
 *      Author: g-1123347
 */
#include "QueueAdt.h"
#ifndef BINTREE_H_
#define BINTREE_H_

class BinTree{
	qnode *root;
public:
	BinTree();
	qnode *insertRecursive(int ,qnode *);
	void displayRecursive(qnode *);
	void in(qnode *);
	void pre(qnode *);
	void post(qnode *);
	qnode *searchRecursive(int ,qnode *);
	void deleteNode(int ,qnode *);
	qnode *mirrorNonRecursive(qnode *);
	int height_nonRec(qnode *);
	
	void displayTree(qnode *);
	qnode *getNode(int);
	qnode *retRoot();
	void insertNode(int,qnode *);
	void preTraverse(qnode *);
	void inTraverse(qnode *);
	void postTraverse(qnode *);
	int search(int,qnode *);
	qnode *delet(qnode*,int);
	void dispLevelWise(qnode *,int);
	qnode *minValueNode(qnode *);
	qnode *mirror(qnode *);
	int height(qnode *);
	virtual ~BinTree();
};

#endif /* BINTREE_H_ */
