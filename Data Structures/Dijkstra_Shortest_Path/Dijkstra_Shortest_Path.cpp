#include<iostream>
#include<stdlib.h>
using namespace std;

//-------CLASS FOR DEFINING THE FUNCTIONS----------
class shortestPath{
	public:
	void dijkstra();
};

//--------FUNCTION TO FIND SHORTEST PATH------------
void shortestPath::dijkstra()
{
	int distance[10],path[20][20],n,v,p,row,column,min,index=1,i,j;
	cout<<"Enter no of nodes :  ";	//-------GETTNG THE NO OF NODES---------
	cin>>n;
	int cost[n][n];
	
	//--------GETTING ADJANCACY COST MATRIX--------
	cout<<"Enter cost matrix :  ";	
	for(int i=1;i<=n;i++)				//---FOR ROW---
	{
		for(int j=1;j<=n;j++)			//---FOR COLUMN---
		{
			cout<<"\nEnter "<<i<<" "<<j<<" : ";
			cin>>cost[i][j];
		}
	}

	//------------DISPLAYING THE GRAPH-------------
	cout<<"\nInput Graph :";
	for(i=1;i<=n;i++)				//---FOR ROW---
	{
		for(j=1;j<=n;j++)			//---FOR COLUMN---
		{
			cout<<"\n"<<i<<" "<<j<<" : "<<cost[i][j];
		}
	}

	//--------GETTING NODE TO BE VISIT--------
	cout<<"Enter node to be visit :  ";	
	cin>>v;
	
	cout<<"Enter paths for the selected node : ";	//ENTER THE NO. OF POSSSIBLE PATH
	cin>>p;
	
	//----------GETTING PATH MATRIX-----------
	cout<<"Enter path matrix "<<endl;		
	cout<<"e.g : 1-->2-->3-->5-->0 (among 1 to 5 are vertices)"<<endl;
	for(i=1;i<=p;i++)
	{
		for(j=1;j<=n;j++)
		{	
			cin>>path[i][j];
		}
	}
	
	//----------MINIMUM DISTANCE------------
	for(i=1;i<=p;i++)
	{
		distance[i]=0;		//DISTANCE MATRIX TO FIND MINIMUM DISTANCE
		row=1;
		for(j=1;j<n;j++)
		{
			if(row!=v)
			{
				//till i visit the last node
				column=path[i][j+1];
				distance[i] =  distance[i]+cost[row][column];	//MIN DISTANCE FORMULA
			}
			row=column;
		}
	}
	//--------WHICH DISTANCE SHOULD BE CONSIDER-------------
	min=distance[1];
	for(i=1;i<=p;i++)
	{
		if(distance[i]<=min)
		{
			min=distance[i];
			index=i;
		}
	}
	
	//----------RESULT--------------
	cout<<"\nMin distance is "<<min;		//MINIMUM DISTANCE'S WEIGHT TOTAL
	cout<<"\nmin distance path is : ";
	for(i=1;i<=n;i++)
	{
		if(path[index][i]!=0)				//PRINTING SORTEST PATH
			cout<<"-->"<<path[index][i];
	}
	cout<<endl;
}	

/*/------DISPLAYING THE GRAPH--------
void display(int n,int **cost){
	if(n){
		cout<<"\nInput Graph is : "<<endl;
		for(int i=1;i<=n;i++)				//---FOR ROW---
		{
			for(int j=1;j<=n;j++)			//---FOR COLUMN---
			{
				cout<<"\n"<<i<<" "<<j<<" : "<<cost[i][j];
			}
		}
	}else{
		cout<<"\nPlz input the graph first !!";
	}
}
*/

//----------MAIN FUNCTION--------------
int main(){
	int ch;
	shortestPath s;			//-----OBJECT OF CLASS----------
	while(1){
		cout<<"\n1.Input\n2.Display\n3.Exit\nEnter Your Choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				s.dijkstra();	
				break;
			case 2:
				//s.display(n,cost);
				break;
			case 3:
				return 0;	
			default :
				cout<<"wrong input";
		}
	}	
}
