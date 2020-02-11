
#include "LinkedList.h"

#ifndef STACKADT_H_
#define STACKADT_H_


//---CLASS FOR DECLARING THE METHODS FOR STACK OPERATIONS---
class StackAdt {
	LinkedList l;
public:
	StackAdt();
	void push(node *);
	node *pop();
	node *peep();
	bool isEmpty();
	virtual ~StackAdt();
};

#endif /* STACKADT_H_ */
