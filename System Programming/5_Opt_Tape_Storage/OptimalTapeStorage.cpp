#include<iostream>
using namespace std;

void getElements(int *,int);
void dispElements(int *,int);
void optimalTape(int *elements,int noE,int *sizeTape,int noTape);
int main(){
	int noE,*elements,noTape,j=0;
	cout<<"ENTER THE NUMBER OF ELEMENTS : ";
	cin>>noE;
	
	elements=new int[noE];
	
	getElements(elements,noE);
	dispElements(elements,noE);
	
	cout<<"\nENTER THE NUMBER OF TAPES : "<<endl;
	cin>>noTape;
	int *sizeTape;
	sizeTape = new int[noTape];	
	while(j!=noTape){
		cout<<"\nENTER THE SIZE OF TAPE "<<j<<" : ";
		cin>>sizeTape[j++];
	}
	
	optimalTape(elements,noE,sizeTape,noTape);	
}

void getElements(int *elements,int noE){
	cout<<"ENTER THE ELEMENTS : "<<endl;
	int i=0;	
	while(i!=noE){
		cout<<"ENTER "<<i<<" : ";
		cin>>elements[i++];		
	}
}


void dispElements(int *elements,int noE){
	cout<<"ELEMENTS ARE : "<<endl;
	int i=0;	
	while(i!=noE){
		cout<<elements[i++]<<"\t";		
	}
}

void optimalTape(int *elements,int noE,int *sizeTape,int noTape){
	int add=0,i=0,j=0;		
	while(j<noTape){
		cout<<"\n----------------Tape "<<j+1<<"-----------------"<<endl;
		cout<<"Size  : "<<sizeTape[j]<<endl;
		add += elements[i];	
		while(add <= sizeTape[j]){
			cout<<elements[i++]<<"\t";			
			add += elements[i];	
		}
		add=0;		
		j++;
	}
}

