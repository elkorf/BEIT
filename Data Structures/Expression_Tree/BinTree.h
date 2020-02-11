
#include "StackAdt.h"

#ifndef BINTREE_H_
#define BINTREE_H_

//CLASS FOR DEFINING THE METHODS
class BinTree{
	node *root;
public:
	//METHODS
	BinTree();
	void displayTree(node *);
	node *getNode(char);
	node *retRoot();
	void getExp(char []);
	node *insertNode(char [],node *);
	void preTraverse(node *);
	void inTraverse(node *);
	void postTraverse(node *);
	
	//NON-RECURSIVE METHODS OF TRAVERSALS
	void in(node *);
	void pre(node *);
	void post(node *);
	virtual ~BinTree();
};

#endif /* BINTREE_H_ */
