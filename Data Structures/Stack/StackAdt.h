#include "LinkedList.h"
#ifndef STACKADT_H_
#define STACKADT_H_
template<typename T>

//---CLASS FOR DECLARING THE METHODS FOR STACK OPERATIONS---
class StackAdt {
	LinkedList<T> l;
public:
	StackAdt();
	void push(T);
	T pop();
	T peep();
	bool isEmpty();
	void display();
	virtual ~StackAdt();
};

#endif /* STACKADT_H_ */
