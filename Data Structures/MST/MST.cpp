//============================================================================
// Name        : Assignment7.cpp
// Author      : Swapnil Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Graph.h"
#include "Graph.cpp"

using namespace std;

//--------MAIN FUNCTION------------
int main() {
	int ch;
	cout<<"\n1.Create Graph\n2.Find MST\nEnter Your Choice : ";
	cin>>ch;
	Graph g;
	g.input();
	return 0;
}
