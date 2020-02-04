#include<iostream>
using namespace std;

void getPrograms(int *,int);
void dispPrograms(int *,int);
void optimalTape(int *programs,int noE,int *sizeTape,int noTape);

struct Tape{
	int size,noE;
	int elements[];
};

void getSizeTapes(struct Tape T[],int noTape){
	for(int i=0;i<noTape;i++){
		cout<<"Enter size of Tape "<<i+1<<" : ";
		cin>>T[i].size;
	}
}

void optimalTape(int *programs,int noP,struct Tape T[],int noTape){	
	int add=0,i=0,j=0,noE=0;		

	while(j<noTape){
		if(programs[i]<=T[j].size){
			T[j].elements[noE++]=programs[i];
			T[j].size -= programs[i++];		
		}else{
			T[j++].noE=noE;
			noE=0;	
		}
	}	
	
	for(int i=0;i<noTape;i++){
		int j=0;
		cout<<"Tape : "<<i+1<<" elements : ";;			
		while(j!=T[i].noE){	
			cout<<T[i].elements[j++];
		}	
	}
}

int main(){
	int noP,j=0,*programs,noTape;
	
	
	cout<<"ENTER THE NUMBER OF PROGRAMS : ";
	cin>>noP;	
	programs=new int[noP];
	getPrograms(programs,noP);	
	dispPrograms(programs,noP);

	cout<<"\nENTER THE NUMBER OF TAPES : "<<endl;
	cin>>noTape;

	struct Tape T[noTape];
	getSizeTapes(T,noTape);
	
	optimalTape(programs,noP,T,noTape);	

}

void sortPrograms(int *programs,int noE){
	for(int i=0;i<noE;i++){
		for(int j=0;j<noE;j++){
			if(programs[i]<programs[j]){
				int temp=programs[i];
				programs[i]=programs[j];
				programs[j]=temp;				
			}		
		}
	}	

}

void getPrograms(int *programs,int noE){
	cout<<"ENTER THE ELEMENTS : "<<endl;
	int i=0;	
	while(i!=noE){
		cout<<"ENTER "<<i<<" : ";
		cin>>programs[i++];		
	}
	sortPrograms(programs,noE);
}



void dispPrograms(int *programs,int noE){
	cout<<"ELEMENTS ARE : "<<endl;
	int i=0;	
	while(i!=noE){
		cout<<programs[i++]<<"\t";		
	}
	cout<<endl;
}


