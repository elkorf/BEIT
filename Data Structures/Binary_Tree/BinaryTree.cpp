/*========================================================================
Roll No		  	  : 23347		Batch: G11 	Class: SEIT 11
Name		  	  : Swapnil Gokool Patil
Assignment No	  : 3
Problem Statement : 
 =========================================================================*/

#include <iostream>
//#include "BinTree.h"
#include "BinTree.cpp"
using namespace std;

//--------MAIN FUNCTION----------------
int main() {
	int ch;
	BinTree b;
	node *rt;
	while(1){
		cout<<"\n1.Insert a Node"<<endl<<"2.Display Tree"<<endl<<"3.Find the Depth of Tree"<<endl<<"4.Display Leaf Nodes"<<endl<<"5.Count of Leaf Node"<<endl<<"6.Create a copy of Tree"<<endl;
		cout<<"Enter your Choice : ";
		cin>>ch;
		switch(ch){
			case 1:
			 	//---INSERT THE NODE--- 
				int val;
				cout<<"Enter Data : ";
				cin>>val;
				b.insertNode(val);
				break;
			case 2:
				//---DISPLAY THE TREE---
				rt=b.retRoot();
				b.displayTree(rt);
				break;
			case 3:
				//---FIND THE DEPTH OF TREE---
				int depth;
				rt=b.retRoot();
				depth=b.findDepth(rt);
				cout<<"Depth of Given Tree is : "<<depth;
				break;
			case 4:
				//---DISPLAYING THE LEAF NODE----
				rt=b.retRoot();
				if(rt!=NULL){
				cout<<"Leaf Nodes : "<<endl;	
				b.leafNodes(rt);
				}else{cout<<"\nTree is already Empty"<<endl;}
				break;
			case 5:
				//---DISPLAYING THE COUNT OF LEAF NODE IN TREE---
				rt=b.retRoot();
				int leaf_count;
				leaf_count=b.leafCount(rt);
				cout<<"\nThere are total "<<leaf_count<<" leaf nodes."<<endl;
				break;
			case 6:
				//---COPY OF TREE---
				cout<<"\nOriginal tree is :"<<endl;
                rt=b.retRoot();
				b.displayTree(rt);
				
				cout<<"\n Copied tree is : "<<endl;
				rt=b.copyTree(rt);
                b.displayTree(rt);
				break;
			case 7:
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
