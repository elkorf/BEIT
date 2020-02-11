#include "LinkedList.h"

#ifndef QUEUEADT_H_
#define QUEUEADT_H_

template<class T>
class QueueAdt {
	//---OBJECT OF LINKED LIST CLASS---
	LinkedList<T> l;
public:
	//---METHODS---
	QueueAdt();
	void enQueue(patient p);
	void deQueue();
	bool isEmpty();
	void display();
	virtual ~QueueAdt();
};

#endif /* QUEUEADT_H_ */
