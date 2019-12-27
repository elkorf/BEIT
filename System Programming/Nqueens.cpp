#include<iostream>
using namespace std;
#include<stdlib.h>
#include <math.h>

int chess[100];
int count=0;

int result(int n)
{
       
	cout<<"\nSolution "<<++count<<endl;
	
	for(int i=1;i<=n;i++)
	{
		cout<<"\t"<<i;
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<"\n"<<i;
		for(int j=1;j<=n;j++)
		{
			if(chess[i]==j)
				cout<<"\tQ";
			else
				cout<<"\t-";
		}
	}
	
	cout<<endl;
}

int place(int k,int j)
{
	//row wise
	for(int i=1;i<=k-1;i++)
	{
		if((chess[i]==j) || (abs(i-k)==abs(chess[i]-j)))
			return 0;
	}
	return 1;
}

void nqueen(int Qno,int TotQueens){
	//column wise
	for(int i=1;i<=TotQueens;i++){
		if(place(Qno,i)){
			chess[Qno]=i;
			if(Qno==TotQueens){
				cout<<"All Queens are place Successfully";
				result(TotQueens);
			}
			else{
				nqueen(Qno+1,TotQueens);
			}		
		}
		
	}	
}

int main(){
	int q;	
	cout<<"Enter how many queens : ";
	cin>>q;
	while(q%4 != 0){
		cout<<"Please...Enter how many queens : ";
		cin>>q;	
	}	
	nqueen(1,q);
}


