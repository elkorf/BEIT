#include "StackAdt.h"
#include "LinkedList.cpp"

//---CONSTRUTOR----
template<class T>
StackAdt<T>::StackAdt() {
	// TODO Auto-generated constructor stub
}

//---INSERTING THE ELEMENT TO STACK---
template<class T>
void StackAdt<T>::push(T val){
	l.insertFirst(val);
}

//---DELETING ELEMENT FROM STACK----
template<class T>
T StackAdt<T>::pop(){
	return(l.delFirst());
}

//---RETRIEVING THE ELEMENT----
template<class T>
T StackAdt<T>::peep(){
	return(l.head->data);
}

//---CHECKING STACK IS EMPTY OR NOT
template<class T>
bool StackAdt<T>::isEmpty(){
	return(l.isEmpty());
}

//---DISPLAYING ALL THE ELEMENTS FROM STACK---
template<class T>
void StackAdt<T>::display(){
	return(l.display());
}

//---DESTRUCTOR--- 
template<class T>
StackAdt<T>::~StackAdt() {
	// TODO Auto-generated destructor stub
}

