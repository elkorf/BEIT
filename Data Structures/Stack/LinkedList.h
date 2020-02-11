#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//---NODE STRUCTURE---
template<typename T>
struct node {
	T data;
	//POINTIGN TO THE SAME STRUCTURE
	node<T> *next;
};

//---CLASS FOR METHOD TO IMPLEMENT LINKED LIST---
template<class T>
class LinkedList {
	public:
	node<T> *head;
public:
	LinkedList();
	void insertFirst(T);
	T delFirst();
	bool isEmpty();
	void display();
	node<T> *getNode();
	virtual ~LinkedList();
};

#endif /* LINKEDLIST_H_ */
