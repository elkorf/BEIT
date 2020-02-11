#include "LinkedList.h"
#include<iostream>
using namespace std;

//-----CONSTRUCTOR-----
template<class T>
LinkedList<T>::LinkedList() {
	// TODO Auto-generated constructor stub
	rear=NULL;
}

//-----CREATING THE NEW NODE-----
template<class T>
node *LinkedList<T>::getNode(){
	node *temp=new node();
	temp->next=NULL;
	return(temp);
}

//----INSERTING THE NEW NODE TO QUEUE-----
template <class T>
void LinkedList<T>::insertFirst(patient p){
	if(rear==NULL)			//IF ALREADY EMPTY
    {
		rear=getNode();
		rear->data=p;
		rear->next=NULL;
    }else					//IF QUEUE ALREADY HAS DATA	
    {
		node *temp=getNode();
		temp=rear;
		if(rear->data.prior<=p.prior){
			node * new1=getNode();
			new1->data=p;
			new1->next=rear;
			rear=new1;
		}
		else{
			while(temp->next!=NULL && temp->data.prior>=p.prior)
			{
				temp=temp->next;
			}
			//---ASSIGNING THE NEW NODE BASED OF PRIORITY---
			node * new1=getNode();
			new1->data=p;
			new1->next=temp->next;
			temp->next=new1;	
		}
	}
}

//---DELETING RECORD FROM FIRST RECORD----
template<class T>
void LinkedList<T>::delFirst(){
	if(rear==NULL){
		//---IF ALREADY EMPTY---
		cout<<"\nNo Queue of Patient's"<<endl;
	}
	else{
		//DISPLAYING THE RECORD RECENTLY DELETED
		node * temp=rear;
		rear=temp->next;
		cout<<"\nRegId\tName\tWeight\tbloodGroup\tAge\tPriority";
		cout<<"\n"<<temp->data.RegId<<"\t"<<temp->data.name<<"\t"<<temp->data.weight<<"\t"<<temp->data.blood<<"\t"<<temp->data.age<<"\t"<<temp->data.prior<<endl<<"Above Record is Assigned to doctor"<<endl;
		delete temp;
	}
}

//---CHECK IF QUEUE IS EMPTY OR NOT---
template<class T>
bool LinkedList<T>::isEmpty(){
	if(rear==NULL)
		return true;
	return false;
}

//----DISPLAYING ALL RECORDS---- 
template<class T>
void LinkedList<T>::display(){
	node *temp=rear;
	if(temp==NULL){
		//IF QUEUE IS ALREADY EMPTY
		cout<<"\nNo Records Are Present !!!"<<endl;
	}
	else{
		cout<<"\nRegId\tName\tWeight\tbloodGroup\tAge\tPriority";
		while(temp!=NULL)
		{
			cout<<"\n"<<temp->data.RegId<<"\t"<<temp->data.name<<"\t"<<temp->data.weight<<"\t"<<temp->data.blood<<"\t"<<temp->data.age<<"\t"<<temp->data.prior;
			temp=temp->next;
		}	 
   }
}

//---DESTRUCTOR---
template<class T>
LinkedList<T>::~LinkedList() {
	// TODO Auto-generated destructor stub
}