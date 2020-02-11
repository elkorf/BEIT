#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//template<typename T>
struct qnode{
	int data;
	qnode *next,*left,*right;
};
//---CLASS FOR DECLARING THE METHODS---
template <class T>
class LinkedList {
	qnode *rear;
public:
	LinkedList();
	void insertFirst(qnode *);
	qnode *delFirst();
	bool isEmpty();
	qnode *getNode();
	int retFirst();
	virtual ~LinkedList();
};

#endif /* LINKEDLIST_H_ */
