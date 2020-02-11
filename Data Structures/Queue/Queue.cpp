/*========================================================================
Roll No		  : 23347		Batch: G11 	Class: SEIT 11
Name		  : Swapnil Gokool Patil
Assignment No	  : 2
Problem Statement : 
 =========================================================================*/
#include <iostream>
#include "QueueAdt.h"
#include "QueueAdt.cpp"
#include<string.h>
using namespace std;

//--------CLASS DATA FOR DECLARING METHODS--------------
class Data{
	//---QUEUEADT OBJECT WITH TYPE PATIENT---
	QueueAdt<patient> q;
	public:
		void insertRecord(int no);	//INSERT
		int getPriority();			//CONDITION OF PATIENT	
		void deleteRecord();		//ASSIGN PATIENT TO DOCTOR
		void displayData();			//DISPLAYING ALL RECORDS
		void bdGroup(patient *);	
};


//------INSERTING THE DATA ACCORDING CONDITION OF PATIENT------
void Data::insertRecord(int i){
	patient p;						//---OBJECT OF STRUCTURE PATIENT---
	p.RegId=i+1+1000;				//---UNIQUE REG ID
	cout<<"\nEnter The Patient's Details : "<<endl;
	int j=0;
//-------FOR VALIDATING THE NAME DO NOT CONAIN THE NUMBERS OR SYMBOLS
	while(p.name[j]!='\0'){
		if(!isalpha(p.name[j])){
			cout<<"\tEnter Valid Name : ";
			cin>>p.name;
			j=0;
		}
		else{
			j++;
		}
	}
	
//------WEIGHT SHOULD BE GREATER THAN 0	----------------
	while(p.weight<1){
		cout<<"\tEnter Valid Weight : ";
		cin>>p.weight;
	}
	
//-----FOR GETTING BLOOD GROUP OF PATIENT		
	bdGroup(&p);
		
//------AGE SHOULD LIES BETWEEN 1 TO 120 YEARS----------		
	while(p.age<1 or p.age>120){	
		cout<<"\tEnter Valid Age(in Years) : ";
		cin>>p.age;
	}
	p.prior=getPriority();	//GETTING THE PRIORITY OF PATIENT BASED ON CONDITION
	q.enQueue(p);			//INSERTING THE RECORD BY CALLING ENQUEUE METHOD
 }
 
 //-------GETTING THE BLOOD GROUP---------------------				
void Data::bdGroup(patient *p){
	int ch,j=1;
	while(j==1){
		cout<<"\tSelect The Blood Group Listed Below : "<<endl<<"1. A+"<<endl<<"2. A-"<<endl<<"3. B+"<<endl<<"4. B-"<<endl<<"5. AB+"<<endl<<"6. AB-"<<endl<<"7. O+"<<endl<<"8. O-"<<endl<<"    : ";
		cin>>ch;
			switch(ch){
				case 1:
					strcpy(p->blood,"A+");
					j=0;
					break;
				case 2:
					strcpy(p->blood,"A-");
					j=0;
					break;
				case 3:
					strcpy(p->blood,"B+");
					j=0;
					break;
				case 4:
					strcpy(p->blood,"B-");
					j=0;
					break;
				case 5:
					strcpy(p->blood,"AB+");
					j=0;
					break;
				case 6:
					strcpy(p->blood,"AB-");
					break;
				case 7:
					strcpy(p->blood,"O+");
					break;
				case 8:
					strcpy(p->blood,"O-");
					j=0;
					break;
				default :
					cout<<"Wrong Input.";							
									
			}
	}
}
		
//------GETTING THE PRIORITY BASED ON PATIENT'S CONDITION-----  
int Data::getPriority(){
	int prior;
	cout<<"\tSelect One : "<<endl<<"\t\t1.Normal"<<endl<<"\t\t2.OPD"<<endl<<"\t\t3.Serious"<<endl<<"\t\t4.Very Serious"<<"\n\tEnter Condition : ";
	cin>>prior;
	if(prior>4 or prior<1){
		return 1;
	}else{
		return prior; 
	}
}

//-----DISPLAYING ALL RECORDS BY CALLING THE METHOD DISPLAY OF QUEUEADT-----
void Data::displayData(){
	q.display();
}

//-----REMOVING THE RECORD AND ASSIGNING TO THE DOCTOR ONE BY ONE-----
void Data::deleteRecord(){
	q.deQueue();
}

//-----------MAIN METHOD-------------
int main() {
	int ch,norc=0;
	Data d;					//OBJECT OF CLASS DATA
	while(1){
		cout<<"\n1.Insert A New Record\n2.Assign next patient to Doctor\n3.Display All Records\n4.Exit\nEnter Your Choice : ";
		cin>>ch;
		switch(ch){
		case 1:
			//------INSERTING THE RECORDS------
			d.insertRecord(norc);
			norc++;						//COUNTER FOR NUMBER OF RECORDS
			break;
		case 2:
			//-------DELETING THE RECORDS--------
			d.deleteRecord();
			norc--;						//COUNTER DECREMENT
			break;
		case 3:
			//------DISPLAYING THE ALL RECORDS------
			d.displayData();
			break;
		case 4:
			//EXIT
			return 0;	
		default:
			cout<<"invalid choice!!!";
		}
	}
	return 0;
}
