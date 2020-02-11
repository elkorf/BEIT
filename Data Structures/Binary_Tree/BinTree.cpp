#include "BinTree.h"
#include <iostream>
using namespace std;

//---CONSTRUCTOR---
BinTree::BinTree()
{
	root=NULL;
}

//---CREATING A NEW NODE AND ASSIGNING THE MEMORY---
node *BinTree::getNode(int data){
	node *temp=new node();
	temp->data=data;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}

//---DISPLAYING THE TREE---
void BinTree::displayTree(node *temp){
	if(temp==NULL){					//IF TREE IS EMPTY
		cout<<"Tree is already Empty";
	}else{
		cout<<"Three Traversal of created tree are : "<<endl;
		cout<<"\nPre-ordered Traversal : ";
		preTraverse(temp);				//PRE-TRAVERSAL
		cout<<"\nIn-ordered Traversal : ";
		inTraverse(temp);				//IN-TRAVERSAL
		cout<<"\nPost-ordered Traversal : ";
		postTraverse(temp);				//POST-TRAVERSAL
	}
}

//----DISPLAYING USING PRE-ORDERED-------
void BinTree::preTraverse(node *temp){
	if(temp!=NULL){
		cout<<temp->data<<" ";
		preTraverse(temp->left);	//RECURSIVE CALL TO ITSELF
	    preTraverse(temp->right);
	}
}

//----DISPLAYING USING IN-ORDERED-------
void BinTree::inTraverse(node *temp){
	if(temp!=NULL)
	{
		inTraverse(temp->left);		//RECURSIVE CALL TO ITSELF
	    cout<<temp->data<<" ";
	    inTraverse(temp->right);
	}
}

//----DISPLAYING USING POST-ORDERED-------
void BinTree::postTraverse(node *temp){
	if(temp!=NULL)
    {
        postTraverse(temp->left);	//RECURSIVE CALL TO ITSELF	
        postTraverse(temp->right);
        cout<<temp->data<<" ";
    }
}

//-------INSERTING THE NEW NODE---------
void BinTree::insertNode(int data){
	int ch;
	if(root==NULL){
	//IF TREE IS EMPTY CREATING NODE AND ASSIGNING TO ROOT NODE	
		cout<<"Making it as a root node."<<endl;
		root=getNode(data);
	}
	else{
		node *temp=root;
		do{
			cout<<"\n1.Left\t2.Right\nEnter The choice : ";
			cin>>ch;			//GETTING CHOICE FROM USER
			if(ch==1){			//CHOICE FOR LEFT NODE
				if(temp->left==NULL){
					temp->left=getNode(data);
					break;
				}else{
					temp=temp->left; //TRAVERSE TILL LEFT IS NOT NULL
				}
			}else if(ch==2){	//CHOICE FOR RIGHT NODE
				if(temp->right==NULL){
					temp->right=getNode(data);
					break;
				}else{
					temp=temp->right;
				}
			}else{
				cout<<"Invalid choice.!!!";
			}
		}while(1);
	}

}

/*---RECURSIVE FUNCTION FOR INSERTING THE NODE-- 
node *BinTree::insertNode(node *temp){
{
	int val;
	cout<<"\n Enter the Data(-1 for NULL): ";
	cin>>val;
	//RETURN NULL IF VALUE IS -1
	if(val==-1)
		return NULL;
	temp = getNode(val);
	
	cout<<"\n Enter Left Child of "<<val;
	temp->left= insertNode(temp->left);
	cout<<"\n Enter Right Child of "<<val;
	temp->right = insertNode(temp->right);
	return temp;
}*/

//---RETURNING THE REFERANCE TO ROOT NODE----
node *BinTree::retRoot(){
	return root;
}

//----------FINDING THE DEPTH----------------
int BinTree::findDepth(node *temp){
	if(temp!=NULL){
        //------CONSIDER THE MAX DEPTH-------
		return 1+max(findDepth(temp->left),findDepth(temp->right));
	}else{
		return 0;
	}
}

//-------DISPLAYING THE LEAF NODES----------
void BinTree::leafNodes(node *temp){
	if(temp!=NULL){
        if(temp->left==NULL && temp->right==NULL){
            cout<<temp->data<<" ";
		}else{
			leafNodes(temp->left);	//RECURSIVE CALL TO ITSELF
			leafNodes(temp->right);	//RECURSIVE CALL TO ITSELF
		}
    }
}

//-----DISPLAYING THE COUNT OF LEAF NODES-----
int BinTree::leafCount(node *temp){
	if(temp==NULL){		//IF EMPTY RETURN 0
		return 0;
	}
    if(temp->left==NULL && temp->right==NULL){	//IF ONLY ROOT THE RETURN 1
        return 1;
	}
    else{ 
        return leafCount(temp->left) + leafCount(temp->right);
	}
}

//-----CREATING COPY OF SAME TREE ------------
node *BinTree::copyTree(node *temp){
	if(temp!=NULL){
		node *p= getNode(temp->data);
		p->left  = copyTree(temp->left);	//RECURSIVE CALL TO ITSELF
		p->right = copyTree(temp->right);	//RECURSIVE CALL TO ITSELF
		return p;
	}	
    //IF TEMP NOT NULL
	else
	{
		return NULL;
	}
}

//-------DESTRUCTOR-----------------
BinTree::~BinTree() {
}
