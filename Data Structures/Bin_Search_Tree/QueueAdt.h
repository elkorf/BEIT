#include "LinkedList.h"
#ifndef QUEUEADT_H_
#define QUEUEADT_H_

template<class T>
class QueueAdt {
	LinkedList<T> l;
public:
	QueueAdt();
	void enQueue(qnode *);
	qnode *deQueue();
	bool isEmpty();
	int front();
	void display();
	virtual ~QueueAdt();
};

#endif /* QUEUEADT_H_ */
