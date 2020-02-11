#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//---STRUTURE FOR PATIENT'S DATA---
struct patient
{
	int prior;
	int RegId;
	int age;
	char name[20];
	double weight;
	char blood[3];
};

//-----STRUCTURE FOR NODE-----
struct node {
	patient data;
	node *next;
};

//---CLASS FOR DECLARING THE METHODS---
template <class T>
class LinkedList {
	public:
	node *rear;
public:
	LinkedList();
	void insertFirst(patient p);
	void delFirst();
	bool isEmpty();
	void display();
	node *getNode();
	virtual ~LinkedList();
};

#endif /* LINKEDLIST_H_ */
