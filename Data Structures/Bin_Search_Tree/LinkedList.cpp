#include "LinkedList.h"
#include<iostream>
using namespace std;

//-----CONSTRUCTOR-----
template<class T>
LinkedList<T>::LinkedList(){
	// TODO Auto-generated constructor stub
	rear=NULL;
}

//-----CREATING THE NEW NODE-----
template<class T>
qnode *LinkedList<T>::getNode(){
	qnode *temp=new qnode();
	temp->next=NULL;
	return(temp);
}

//----INSERTING THE NEW NODE TO QUEUE-----
template <class T>
void LinkedList<T>::insertFirst(qnode *p){
	if(rear==NULL)			//IF ALREADY EMPTY
    {
		rear=getNode();
		rear=p;
		rear->next=NULL;
    }else					//IF QUEUE ALREADY HAS DATA	
    {
		qnode *temp=getNode();
		temp=rear;
		qnode * new1=getNode();
		new1=p;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new1;
	}
}

//---DELETING RECORD FROM FIRST RECORD----
template<class T>
qnode *LinkedList<T>::delFirst(){
	if(rear==NULL){
		return NULL;
	}
	else{
		//DISPLAYING THE RECORD RECENTLY DELETED
		qnode *temp=rear;
		rear=temp->next;
		return temp;
	}
}

template<class T>
int LinkedList<T>::retFirst(){
	return rear->data;
}
//---CHECK IF QUEUE IS EMPTY OR NOT---
template<class T>
bool LinkedList<T>::isEmpty(){
	if(rear==NULL)
		return true;
	return false;
}

//---DESTRUCTOR---
template<class T>
LinkedList<T>::~LinkedList() {
	// TODO Auto-generated destructor stub
}
