#include "LinkedList.h"
#include<iostream>
using namespace std;

//-------CONSTRUCTOR----------
LinkedList::LinkedList() {
	// TODO Auto-generated constructor stub
	head=NULL;
}
//-------INSERT AT FIRST------
void LinkedList::insertFirst(node *temp){
	//temp=getNode();
	temp->next=head;
	head=temp;
}

//-----DELETE FROM LAST-------
node *LinkedList::delFirst(){
	node *temp=head;
	//char val = temp->data;
	head=temp->next;
	return temp;
}

//----CHECK FOR EMPTY STACK---
bool LinkedList::isEmpty(){
	if(head==NULL)
		return true;
	return false;
}

//-----DESTRUCTOR--------
LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

