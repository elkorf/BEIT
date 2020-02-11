#include "StackAdt.h"
#include "LinkedList.cpp"


//---CONSTRUTOR----

StackAdt::StackAdt() {
	// TODO Auto-generated constructor stub
}

//---INSERTING THE ELEMENT TO STACK---
void StackAdt::push(node *temp){
	l.insertFirst(temp);
}

//---DELETING ELEMENT FROM STACK----

node *StackAdt::pop(){
	return(l.delFirst());
}

//---RETRIEVING THE ELEMENT----

node *StackAdt::peep(){
	return(l.head);
}

//---CHECKING STACK IS EMPTY OR NOT

bool StackAdt::isEmpty(){
	return(l.isEmpty());
}

//---DESTRUCTOR--- 

StackAdt::~StackAdt() {
	// TODO Auto-generated destructor stub
}

