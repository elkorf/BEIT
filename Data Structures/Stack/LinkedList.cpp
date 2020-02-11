#include "LinkedList.h"
#include<iostream>
using namespace std;

//-------CONSTRUCTOR----------
template<class T>
LinkedList<T>::LinkedList() {
	// TODO Auto-generated constructor stub
	head=NULL;
}

//------GETTING NEW NODE------
template<class T>
node<T> * LinkedList<T>::getNode(){
	node<T> *temp=new (node<T>);
	temp->next=NULL;
	return(temp);
}

//-------INSERT AT FIRST------
template <class T>
void LinkedList<T>::insertFirst(T val){
	node<T> *temp=getNode();
	temp->data=val;
	temp->next=head;
	head=temp;
}

//-----DELETE FROM LAST-------
template<class T>
T LinkedList<T>::delFirst(){
	node<T> *temp=head;
	T val=temp->data;
	head=temp->next;
	delete temp;
	return val;
}

//----CHECK FOR EMPTY STACK---
template<class T>
bool LinkedList<T>::isEmpty(){
	if(head==NULL)
		return true;
	return false;
}

//---DISPLAYING THE STACK ELEMENTS
template<class T>
void LinkedList<T>::display(){
	node<T> *temp=head;
	if(!isEmpty()){
		while(temp!=NULL){
			cout<<"\n\t"<<temp->data;
			temp=temp->next;
		}
	}else{
		cout<<"Stack is Already Empty";
	}
}

//-----DESTRUCTOR--------
template<class T>
LinkedList<T>::~LinkedList() {
	// TODO Auto-generated destructor stub
}

