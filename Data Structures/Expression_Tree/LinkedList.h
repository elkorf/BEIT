#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//---NODE STRUCTURE---
struct node{
	char data;
	node *left,*right,*next;
};

//---CLASS FOR METHOD TO IMPLEMENT LINKED LIST---
class LinkedList {
	public:
	node *head;
public:
	LinkedList();
	void insertFirst(node *);
	node *delFirst();
	bool isEmpty();
	virtual ~LinkedList();
};

#endif /* LINKEDLIST_H_ */
