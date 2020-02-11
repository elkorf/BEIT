//============================================================================
// Name        : Assignment4.cpp
// Author      : Swapnil Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
	
#include <iostream>
#include "BinTree.h"
#include "BinTree.cpp"
using namespace std;

//-----------MAIN FUNCTION------------
int main() {
	BinTree b;
	int ch;
	char exp[20];
	node *rt;	
	while(1){
		cout<<"\n1.Create a Tree"<<endl<<"2.Display Tree"<<endl<<"3.Exit"<<endl;
		cout<<"Enter your Choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				//----INSERT-----
				b.getExp(exp);
				rt=b.retRoot();
				rt=b.insertNode(exp,rt);
				break;
			case 2:
				//----DISPLAY------
				b.displayTree(rt);
				break;
			case 3:
				//EXIT
				return 0;
				break;
			default:
				cout<<"Invalid Choice.!!!";
				break;
			}
		}
	return 0;
}
