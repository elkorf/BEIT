#include "Graph.h"
#include <iostream>
using namespace std;

//---------CONSTRUCTOR------------------
Graph::Graph() {
	// TODO Auto-generated constructor stub
}

//-------INPUT FUNCTION----------------
void Graph::input(){
	int k=1,sp[20][20];
	int noV,noE,weight;
	//------TAKING THE NO. OF VERTICES------
	cout<<"Enter the number of vertices  : ";
	cin>>noV;
	//------TAKING THE NO. OF EDGES-------
	cout<<"Enter the number of edges  : ";
	cin>>noE;

	edge e[noE];	//CREATING OBJECT WITH SIZE OF NO.OF EDGES
	cout<<"Enter the edges :  (source : destination : weight)"<<endl;
	for(int j=0;j<noE;j++){
		int u,v,w;
		cout<<"\nEnter Edge "<<j+1<<" : ";
		cin>>u>>v>>w;//TAKING THE EDGE AND ITS WEIGHT
		e[j].u=u;
		e[j].v=v;
		e[j].w=w;
	}

	//-------PRINTING THE GRAPH--------
	cout<<"\nBefore Sorting the input edges are : "<<endl;
	cout<<"\nSource : destination : weight"<<endl;
	for(int i=0;i<noE;i++){
		cout<<"\t"<<e[i].u<<" ";
		cout<<e[i].v<<" ";
		cout<<e[i].w<<" ";
		cout<<"\n";
	}
	//--------CALL SORT FUNCTION TO SORT EDGES IN ASCENDING ORDER OF WEIGHT------
	sort(e,noE);

	//-------PRINTING THE GRAPH AFTER SORTING--------
	cout<<"\nAfter Sorting the input edges are : "<<endl;
	cout<<"\nSource : destination : weight"<<endl;
	for(int i=0;i<noE;i++){
			cout<<"\t"<<e[i].u<<" ";
			cout<<e[i].v<<" ";
			cout<<e[i].w<<" ";
		cout<<"\n";
	}
	//---------CALL KRUSKAL FUNCTION TO FIND MST
	kruskals(e,noV,noE);
}

//---------SORT FUNCTION-----------------
void Graph::sort(edge e[],int row ){
	for(int i=0;i<row-1;i++){
		for(int j=0;j<row-1;j++){
			if(e[j].w > e[j+1].w){	//IF FIRST EDGE IS GREATER THAN ITS NEXT THEN SWAP
				edge e1=e[j];
				e[j]=e[j+1];
				e[j+1]=e1;
			}
		}
	}
}

//--------KRUSKAL FUNCTION TO FIND MST------------
void Graph::kruskals(edge e[],int noV,int noE){
	int count=0,i;
	edge op[noV-1];		//TO STORE THE SELECTED EDGES
	int parent[noV+1];	//TO STORE IF EDGE IS ALREADY VISITED OR NOT
	for(i=1;i<=noV;i++)
		parent[i]=i;
	i=0;
	while(count!=(noV-1)){	//WHILE ALL THE VERTICES NOT COVER
		edge currEdge=e[i];

		int sourceP=findParent(currEdge.u,parent);	//FINDING ITS VISITED BEFORE OR NOT
		int destP=findParent(currEdge.v,parent);	//FINDING ITS VISITED BEFORE OR NOT

		if(sourceP!=destP){			//IF NOT VISITED
			op[count]=currEdge;		//ADD TO OUTPUT ARRRAY
			count++;
			parent[destP]=sourceP;	//MAKE UNION OF BOTH
		}
		i++;
	}

	//-----FOR PRINTING THE MST-----------------
	cout<<"\nHere is the Minimum Spanning Tree : "<<endl;
	cout<<"\nSource : Destination : Weight "<<endl;
	for(int i=0;i<noV-1;i++){
			cout<<op[i].u<<" "<<op[i].v<<" "<<op[i].w<<endl;
	}

	//-------TO FIND TOTAL WEIGHT OF MST-----------
	int  res=0;
	for(int i=0;i<noV-1;i++){
		res=res+op[i].w;
	}
	cout<<"\n Final Weight : "<<res<<endl;	//FINAL WEIGHT

}

//-----------CHECK IF VISITED OR NOT--------------
int Graph::findParent(int a,int parent[]){
	if(parent[a]==a){
		return a;
	}
	return findParent(parent[a],parent);
}

//--------DESTRUCTOR--------------------------
Graph::~Graph() {
	// TODO Auto-generated destructor stub
}
