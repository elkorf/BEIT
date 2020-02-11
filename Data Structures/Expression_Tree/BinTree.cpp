#include <iostream>
#include "BinTree.h"
#include "StackAdt.cpp"
using namespace std;


StackAdt s;	//OBJECT OF STACKADT

//----CONSTRUCTOR-------

BinTree::BinTree()
{
	root=NULL;
}

//----GETTING NEW NODE---------

node *BinTree::getNode(char val){
	node *temp=new node();
	temp->data=val;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}

//---GETTING THE EXPRESSION------
void BinTree::getExp(char exp[]){
	cout<<"Enter the Expression : ";
	cin>>exp;
	int i=0,c1=0,c2=0;
	/*do
	{
		if(exp[i]=='('){
		}
		if(exp[i]==')'){
			c2++;
		}
		else{
			i++;
		}
		if(c1!=c2){
			cout<<c1<<" "<<c2;
			cout<<"Enter the Expression again : ";
			cin>>exp;
			i=0;
		}else{
			break;
		}
		i++;
		
	}while(c1!=c2);
	
//----CHECKING THE TWO OPRATORS OR TWO OPERAND ARE TOGETHER IN INFIX EXPRESSION----
	int len=strlen(exp);
	while(exp[i]!='\0')
	{
		if((!isalnum(exp[i]) and !isalnum(exp[i+1])) or (isalpha(exp[i])) and isalpha(exp[i])) or !isalnum(exp[i]) or !isalnum(exp[len-1])){
			cout<<"Enter the Expression again : ";
			cin>>exp;
			i=0;
		}
		else{
			i++;
		}
	}*/
}

//------DISPLAYING THE EXPRESSION TREE-------

void BinTree::displayTree(node *temp){
	int ch;
	if(temp==NULL){			//IF EMPTY
		cout<<"Tree is already Empty";
	}else{
		//ASKING FOR RECURSIVE OR NON-RECURSIVE
		cout<<"\n1.Recursive "<<endl<<"2.Non-Recursive "<<endl<<"Enter your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				//-----------------FOR RECURSIVE------------------------
				cout<<"Three Recursive Traversal of created tree are : "<<endl;
				cout<<"\nPre-ordered Traversal : ";
				preTraverse(temp);
				cout<<"\nIn-ordered Traversal : ";
				inTraverse(temp);
				cout<<"\nPost-ordered Traversal : ";
				postTraverse(temp);
				break;
			case 2:
				//----------------FOR NON-RECURSIVE----------------------
				cout<<"Three Non-Recursive Traversal of created tree are : "<<endl;
				cout<<"\nPre-ordered Traversal : ";
				pre(temp);
				cout<<"\nIn-ordered Traversal : ";
				in(temp);
				cout<<"\nPost-ordered Traversal : ";
				post(temp);
				break;
		}
	}
}

//-------PRE-ORDER TRAVERSAL---------

void BinTree::preTraverse(node *temp){
	if(temp!=NULL){
		cout<<temp->data<<" ";
	    preTraverse(temp->left);
	    preTraverse(temp->right);
	}
}

//-------IN-ORDER TRAVERSAL---------
void BinTree::inTraverse(node *temp){
	if(temp!=NULL)
	{
		inTraverse(temp->left);
	    cout<<temp->data<<" ";
	    inTraverse(temp->right);
	}
}

//-------POST-ORDER TRAVERSAL---------
void BinTree::postTraverse(node *temp){
   
	if(temp!=NULL)
    {
        postTraverse(temp->left);
        postTraverse(temp->right);
        cout<<temp->data<<" ";
    }
}

//-------INSERTING THE NEW NODE---------
node *BinTree::insertNode(char exp[],node *temp){	
	int i=0;
	while(exp[i]!='\0'){		//TILL EOE	
		if(isalnum(exp[i])){
			temp=getNode(exp[i]);
			s.push(temp);
		}else{
			temp=getNode(exp[i]);
			temp->right=s.pop();
			temp->left=s.pop();
			s.push(temp);
		}
		i++;	
	}
	return temp;
}

//----NON-RECURSIVE ALGO FOR TRAVERSALS-------
//------PRE-ORDER---------
void BinTree::pre(node *temp){
	while(!s.isEmpty()) //WHILE TRUE
    {
        //WHILE TEMP NOT NULL
        while(temp != NULL)
        {	
			cout<<temp->data<<" ";
            if (temp->right!=NULL)
                s.push(temp->right);
            temp = temp->left;
        }
        temp = s.peep();
        s.pop();
        
    }
}

//------IN-ORDER---------

void BinTree::in(node *temp){
    while(1)
    {
        //IF TEMP NOT NULL
        while(temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        if(s.isEmpty()) //IF STACK WAS EMPTY
            break;
        temp = s.peep();
        s.pop();
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}

//------POST-ORDER---------
void BinTree::post(node *temp){
	node *prev;
	s.push(temp);
	while(!s.isEmpty()){
		temp=s.pop();
		if(temp->right==NULL && temp->left==NULL){
			cout<<temp->data<<" ";
			prev=temp;
		}else if(temp->left==prev || temp->right==prev){
			cout<<temp->data<<" ";
			prev=temp;
		}else{
			s.push(temp);
			if(temp->right){
				s.push(temp->right);			
			}
			if(temp->left){
				s.push(temp->left);
			}
		}
	}
}

node *BinTree::retRoot(){
	return root;
}

//----DESTRUCTOR-------
BinTree::~BinTree() {
	
}
