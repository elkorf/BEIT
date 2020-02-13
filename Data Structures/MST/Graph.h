#ifndef GRAPH_H_
#define GRAPH_H_
#define MAX 20

//---------STRUCTURE OF NODE--------------
struct edge{
	int u,v,w;
};

//-----CLASS FOR DEFINING THE METHODS-----
class Graph {
public:
	Graph();
	void input();		//GETTING THE INPUT
	void sort(edge [],int );		//SORITNG THE EDGES
	void print();					//PRITING THE GRAPH
	int findParent(int ,int []);
	void kruskals(edge [20],int ,int);	//TO FIND MST
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
