#include "QueueAdt.h"
#include "LinkedList.cpp"

//-----CONSTRUCTOR-------
template<class T>
QueueAdt<T>::QueueAdt() {
	// TODO Auto-generated constructor stub
}

//----INSERTING THE DATA-----
template<class T>
void QueueAdt<T>::enQueue(patient p){
	l.insertFirst(p);
}

//----REMOVING THE DATA------
template<class T>
void QueueAdt<T>::deQueue(){
	l.delFirst();
}

//----CHECK IF QUEUE IS EMPTY----
template<class T>
bool QueueAdt<T>::isEmpty(){
	return(l.isEmpty());
}

//----DISPLAY THE ALL CONTENTS OF QUEUE----
template<class T>
void QueueAdt<T>::display(){
	l.display();
}

//----DESTRUCTOR-----
template<class T>
QueueAdt<T>::~QueueAdt() {
	// TODO Auto-generated destructor stub
}

