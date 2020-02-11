//============================================================================
// Name        : Assignment5.cpp
// Author      : Swapnil Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinTree.h"
#include "BinTree.cpp"
using namespace std;

int main() {
	int ch,data,count,ch2;
	BinTree b;
	qnode *rt;
	while(1){
		cout<<"\n1.Insert a Node"<<endl<<"2.Display Tree"<<endl<<"3.Search a data"<<endl<<"4.Delete a node"<<endl<<"5.Mirror Image"<<endl<<"6.Display Tree level wise"<<endl<<"7.Height of Tree"<<endl<<"8.Exit"<<endl;
		cout<<"Enter your Choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				int val;
				cout<<"\tEnter Data : ";
				cin>>val;
				rt=b.retRoot();
				cout<<"\n\t1.Recursive\n\t2.Non-Recursive\n\tEnter Choice : ";
				cin>>ch2;
				if(ch2==1){
					rt=b.insertRecursive(val,rt);
				}else{
					b.insertNode(val,rt);
				}
				count++;
				break;
			case 2:
				rt=b.retRoot();
				b.displayTree(rt);
				break;
			case 3:
				//SEARCH THE NODE
				rt=b.retRoot();
				cout<<"\n\tEnter The data to be search : ";
				cin>>data;
				cout<<"\n\t1.Recursive\n\t2.Non-Recursive\n\tEnter Choice : ";
				cin>>ch2;
				if(ch2==1){
					if(b.searchRecursive(data,rt)->data==data){
						cout<<"\t"<<data<<" is found in Tree.";
					}else{
						cout<<"\tData not found in Tree";
					}
				}else{
					if(b.search(data,rt)){
						cout<<"\t"<<data<<" is found in Tree.";
					}else{
						cout<<"\tData not found in Tree";
					}	
				}
				break;
			case 4:
				//DELETE THE NODE
				int key;
				rt=b.retRoot();
				cout<<"\tEnter Key want to delete : ";
				cin>>key;
				cout<<"\n\t1.Recursive\n\t2.Non-Recursive\n\tEnter Choice : ";
				cin>>ch2;
				
				if(ch2==1){
					//RECURSIVE
					rt=b.delet(rt,key);
					b.displayTree(rt);
				}else{
					//NON-RECURSIVE
					//b.deleteNode(key,rt);
					b.displayTree(rt);		
				}
				count--;
				break;
			case 5:
				//CREATING THE MIRROR IMAGE OF TREE
				rt=b.retRoot();
				cout<<"\n\t1.Recursive\n2.Non-Recursive\nEnter Choice : ";
				cin>>ch2;
				if(rt==NULL){cout<<"\tEmpty";}
				else{
					cout<<"\tMirror Image of Tree is : "<<endl;
					if(ch2==1){
						rt=b.mirror(rt);
						b.displayTree(rt);	
					}else{
						rt=b.mirrorNonRecursive(rt);
						b.displayTree(rt);
					}
				}
				break;
			case 6:
				//DISPLAY TREE LEVEL WISE
				rt=b.retRoot();
				cout<<"\n\t1.Recursive\n2.Non-Recursive\nEnter Choice : ";
				cin>>ch2;
				if(ch2==1){
				}else{
					cout<<"\n\tLevel order of tree is : ";
					b.dispLevelWise(rt,count);
				}
				break;
			case 7:
				//CALCULATE HEIGHT OF TREE
				cout<<"\n\t1.Recursive\n2.Non-Recursive\nEnter Choice : ";
				cin>>ch2;
				rt=b.retRoot();
				if(ch2==1){
					cout<<"Height of Tree is : "<<b.height(rt);
				}else{
					//cout<<"Height of Tree is : "<<b.height_nonRec(rt);
				}
				break;
			case 8:
				return 0;
			default:
				cout<<"Invalid Choice.!!!";
				break;
			}
		}
	return 0;	
}
