#include<iostream>
using namespace std;
#define MX 20

//-------CLASS FOR DECLARING THE METHODS
class mst{
	public :	
	void prims();	
};

//-------PRIM'S ALGORITHM TO FIND MST----
void mst::prims(){
	int min=9999,row,col,index=0,visited[MX],minlist[MX],total=0;
	
	int noV,noE;
	cout<<"Enter the number of vertices  : ";	//GETTING THE NO OF VERTICES
	cin>>noV;
	
	cout<<"Enter the number of edges  : ";		//GETTING THE NO OF EDGES
	cin>>noE;
	
	int edges[noE][noE];			//--CREATING THE NORMAL MATRIX--
	
	for(int i=0;i<=noE;i++){
		visited[i]=minlist[i]=0;
		for(int j=0;j<=noE;j++){	
			edges[i][j]=0;			//CONVERTING INTO SPARSE MATRIX	
		}
	}
	
	//--------GETTING THE EDGES WITH THEIR WEIGHTS--------
	for(int i=0;i<noE;i++){
		
		int f,s,w;
		cout<<"f : s : w : ";
		cin>>f>>s>>w;			//SOURCE //DEST //WEIGHT
		edges[f][s]=w;
		edges[s][f]=w;
	}
	
	//---------DISPLAYING THE GRAPH---------------
	cout<<"\nInput Graph is : ";
	cout<<"\n\tf : s : w : ";
	for(int i=1;i<=noE;i++){
		for(int j=1;j<=noE;j++){
		if(edges[i][j]!=0)
			cout<<"\n\t"<<i<<" "<<j<<" : "<<edges[i][j];				//SOURCE //DEST //WEIGHT
		}
	}
	cout<<endl;
	//------FINDING MINIMUM DISTANCE------------
	for(int i=0;i<noV;i++){
		for(int j=i;j<noV;j++){
			if(edges[i][j]<min && edges[i][j]!=0){
				min=edges[i][j];		
				row=i;
				col=j;
			}
		}
	}
	
	visited[row]=visited[col]=1;	//MARK AS VISITED
	minlist[index++]=min; 			//PRINT
	
	//--------ALTERNATIVE EGDES BELONGS TO MINIMUM PATH----
	for(int i=0;i<noV-2;i++){
		min=9999;
		for(int j=0;j<noV+1;j++){
			if(visited[j]==1){		//ONLY VISITED EDGES
				for(int k=0;k<noV+1;k++){
					if(edges[j][k]<min && edges[j][k]!=0 && visited[k]==0){
						min=edges[j][k];
						row=j;
						col=k;
					}
				}
			}
		}
		
		minlist[index++]=min;			//----PRINT------
		visited[row]=visited[col]=1;	//MARK AS VISITED
	}
	
	//-------DISPLAYING THE PATH OF MST------------
	cout<<"\nTHE PATH OF MINIMUM SPANNING TREE COSTS ARE  : "<<endl;
	for(int i=0;i<noV-1;i++){
		cout<<minlist[i]<<"-->";
		total=total+minlist[i];
	}
	
	//-------PRINTING THE FINAL TOTAL WEIGHT----------
	cout<<"\nCOST IS : "<<total<<endl;
}

//-------------MAIN FUNCTION---------------
int main(){
	int ch;
	mst m;
	while(1){
		cout<<"\n1.Input\n2.Display\n3.Exit\nEnter Your Choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				m.prims();
				break;
			case 2:
				//m.display();
				break;
			case 3:
				return 0;	
			default :
				cout<<"wrong input";
		}
	}
}
