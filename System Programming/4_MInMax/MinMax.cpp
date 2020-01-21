#include<iostream>
#include<stdlib.h>
using namespace std;

//------------------------------PROTOTYPES----------------------------
void getData(int *,int);
int MinMax(int *,int ,int,int *);
int main(){

	int no,*elements,*res,lower=0;
	cout<<"Enter the no of elements : ";
	cin>>no;	
	while(no<1){	
		cout<<"The elements number cannot be less than 1  : "; 
		cin>>no;
	}	
	
	//MEMORY ALLOCATION	
	elements = new int;
	res = new int[2];
	res[0]=0;res[1]=0;
	//GETTING ELEMENTS	
	getData(elements,no);
	if(no==1){
		res[0]=elements[0];
		res[1]=elements[0];
	}else if(no==2){
		if(elements[0]>elements[1]){
			res[1]=elements[0];
			res[0]=elements[1];
		}else{
			res[0]=elements[0];
			res[1]=elements[1];
		}
	}else{	
		res=MinMax(elements,lower,no-1,res);
	}	
	cout<<"------------Result-------------"<<endl<<"Minimum  : "<<res[0]<<endl<<"Maximum : "<<res[1]<<endl;
}

//--------------------GETTING THE DATA FROM USER-----------------------
void getData(int *elements,int no){
	cout<<"Enter the Numbers : "<<endl;
	for(int i=0;i<no;i++){
		cout<<"Enter "<<i+1<<" : ";
		cin>>elements[i];		
	}
	for(int i=0;i<no;i++){
		//cout<<"Enter "<<i+1<<" : ";
		cout<<elements[i];		
	}
}

int *MinMax(int *elements,int l,int h,int *res){
	int *Rminmax,*Lminmax;	
	int mid = (l+h)/2;
	Rminmax= new int[2];
	Lminmax = new int[2];
	
	Lminmax = MinMax(elements,l,mid,res);
	//traverse right
	Rminmax = MinMax(elements,mid+1,h,res);
	if(Lminmax[0] < Rminmax[0])
		res[0]=Lminmax[0];
	else
		res[0]=Rminmax[0];
	if(Lminmax[1] > Rminmax[1])
		res[1]=Lminmax[1];
	else
		res[1]=Rminmax[1];	
	free(Lminmax);
	free(Rminmax);
	return res;
}	
