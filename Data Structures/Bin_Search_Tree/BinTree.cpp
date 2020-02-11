/*
 * BinTree.cpp
 *
 *  Created on: 22-Jan-2019
 *      Author: g-1123347
 */
#include <iostream>
#include "BinTree.h"
#include "QueueAdt.cpp"
using namespace std;

//CONSTRUCTOR TO INITIALIZE THE POINTERS
BinTree::BinTree()
{
	root=NULL;
}

//CREATING THE NEW NODE AND ASSIGN THE DATA TO IT
qnode *BinTree::getNode(int data){
	qnode *temp=new qnode();
	temp->data=data;
	temp->right=NULL;		//MAKE LEFT AND RIGHT POINTERS NULL
	temp->left=NULL;
	return temp;
}

//DISPLAYING THE TREE
void BinTree::displayTree(qnode *temp){
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
				//pre(temp);
				cout<<"\nIn-ordered Traversal : ";
				//in(temp);
				cout<<"\nPost-ordered Traversal : ";
				//post(temp);
				break;
		}
	}
}

//PRE-TRAVERSAL ROOT->LEFT->RIGHT
void BinTree::preTraverse(qnode *temp){
	if(temp!=NULL){
		cout<<temp->data<<" ";		//DISPLAYING DATA
	    preTraverse(temp->left);	//RECURSIVE CALL WITH ROOT->LEFT NODE
	    preTraverse(temp->right);	//RECURSIVE CALL WITH ROOT->RIGHT NODE
	}
}

//IN-TRAVERSAL LEFT->ROOT->RIGHT
void BinTree::inTraverse(qnode *temp){
	if(temp!=NULL)
	{
		inTraverse(temp->left);		//RECURSIVE CALL WITH ROOT->LEFT NODE
	    cout<<temp->data<<" ";		//DISPLAYING DATA
	    inTraverse(temp->right);	//RECURSIVE CALL WITH ROOT->RIGHT NODE
	}
}

//POST-TRAVERSAL LEFT->RIGHT->ROOT
void BinTree::postTraverse(qnode *temp){
   
	if(temp!=NULL)		//IF TREE IS EMPTY
    {
        postTraverse(temp->left);	//RECURSIVE CALL WITH ROOT->LEFT NODE
        postTraverse(temp->right);	//RECURSIVE CALL WITH ROOT->RIGHT NODE
        cout<<temp->data<<" ";		//DISPLAYING DATA
    }
}

/*/----NON-RECURSIVE ALGO FOR TRAVERSALS-------
//------PRE-ORDER---------
void BinTree::pre(qnode *temp){
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

void BinTree::in(qnode *temp){
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
void BinTree::post(qnode *temp){
	qnode *prev;
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
*/
//INSERTING THE NEW NODE
void BinTree::insertNode(int data,qnode *temp){
	if(root==NULL){		//TREE IS EMPTY THEN MAKE THE NODE AS ROOT NODE
		root=getNode(data);
	}
	else{
		do{
			if(temp->data > data){
				if(temp->left==NULL){
						temp->left=getNode(data);
						break;
				}
				else{
					temp=temp->left;
					continue;
				}
			}
			else if(temp->data < data){
				if(temp->right==NULL){
					temp->right=getNode(data);
					break;
				}else{
					temp=temp->right;
					continue;
				}
			}

		}while(1);
	}
}

//RECURSIVE--INSERTING THE NEW NODE
qnode *BinTree::insertRecursive(int data,qnode *rt){
	if(root==NULL){		//TREE IS EMPTY THEN MAKE THE NODE AS ROOT NODE
		root=getNode(data);
		return root;
	}else{
		if(data < rt->data){
			if(rt->left!=NULL){
				rt->left=insertRecursive(data,rt->left);
			}else{
				rt->left=getNode(data);
			}
		}
		else if(data > rt->data){
			if(rt->right!=NULL){
				rt->right=insertRecursive(data,rt->right);
			}else{
				rt->right=getNode(data);
			}
		}
		return rt;
	}
}

//RETURN ADDRESS OF ROOT NODE
qnode *BinTree::retRoot(){
	return root;
}

//SEARCHING THE PARTICULAR DATA
int BinTree::search(int data,qnode *temp){
	while(temp!=NULL){
		if(temp->data==data){
			return 1;
		}
		else if(temp->data > data){
			temp=temp->left;
		}
		else if(temp->data < data){
			temp=temp->right;
		}
	}
	return 0;
}

//RECURSIVE--SEARCHING THE PARTICULAR DATA
qnode *BinTree::searchRecursive(int data,qnode *temp){
	if(temp==NULL){
		cout<<"\nTree is empty"<<endl;
	}else{
		if(data < temp->data){
			temp=searchRecursive(data,temp->left);
		}
		else if(data > temp->data){
			temp=searchRecursive(data,temp->right);
		}else{
			return temp;
		}
	}
}

//MINIMUM VALUE FOR DELETE PERPOSE
qnode * BinTree::minValueNode(qnode* temp) 
{  
    while (temp->left != NULL) 
        temp= temp->left; 
  
    return temp; 
} 

//RECURSIVE--DELETING THE NODE FROM TREE
qnode *BinTree::delet(qnode *root,int key){
	 // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->data) 
        root->left = delet(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->data) 
        root->right = delet(root->right, key); 
  
    // if key is same as root's key, then This is the qnode 
    // to be deleted 
    else
    { 
        // qnode with only one child or no child 
        if (root->left == NULL) 
        { 
            qnode *temp = root->right; 
            delete root; 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            qnode *temp = root->left; 
            delete root; 
            return temp; 
        } 
  
        // qnode with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        qnode* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this qnode 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->right = delet(root->right, temp->data); 
    } 
    return root; 
}

//DELETING THE NODE FROM TREE
/*
void deleteNode(qnode *temp,int key)
{
	// pointer to store parent node of current node
	qnode* parent =	NULL;

	// start with root node
	qnode* curr = temp;

	// search key in BST and set its parent pointer
	qnode *s=searchRecursive(key,curr);

	// return if key is not found in the tree
	if (curr == NULL)
		return;

	// Case 1: node to be deleted has no children i.e. it is a leaf node
	if (curr->left == NULL && curr->right == NULL)
	{
		// if node to be deleted is not a root node, then set its
		// parent left/right child to null
		if (curr != temp)
		{
			if (parent->left == curr)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		// if tree has only root node, delete it and set root to null
		else
			temp = NULL;

		// deallocate the memory
		delete curr;	 // or delete curr;
	}

	// Case 2: node to be deleted has two children
	else if (curr->left && curr->right)
	{
		// find its in-order successor node
		qnode* successor  = minValueNode(curr->right);

		// store successor value
		int val = successor->data;

		// recursively delete the successor. Note that the successor
		// will have at-most one child (right child)
		deleteNode(temp, successor->data);

		// Copy the value of successor to current node
		curr->data = val;
	}

	// Case 3: node to be deleted has only one child
	else
	{
		// find child node
		qnode* child = (curr->left)? curr->left: curr->right;

		// if node to be deleted is not a root node, then set its parent
		// to its child
		if (curr != temp)
		{
			if (curr == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}

		// if node to be deleted is root node, then set the root to child
		else
			temp = child;

		// deallocate the memory
		delete curr;
	}
}
*/

//DISPLAY TREE LEVEL WISE
void BinTree::dispLevelWise(qnode *temp,int counts)  
{  
    // Base Case  
    if (temp == NULL) return;  
	else if (temp->left==NULL && temp->right==NULL){
		cout<<temp->data;
		return;
	}else{
    // Create an empty queue for level order tarversal  
    QueueAdt<qnode *> q;   
	// Enqueue Root
    q.enQueue(temp);  
		int nodeCount = counts; 
			while (nodeCount > 0) 
			{    
				int d;
				d = q.front();		
				cout<<d<< " ";
				qnode *p=q.deQueue();		
				if (p->left != NULL)  
					q.enQueue(p->left);  
				if (p->right != NULL)  
					q.enQueue(p->right);
				nodeCount--;  
			}  
			cout << endl;  
	}	
	
}  

//RECURSIVE--CREATING THE MIRROR IMNAGE OF TREE
qnode *BinTree::mirror(qnode *temp){ 
	if (temp!=NULL){ 
		qnode *p= getNode(temp->data);
		p->right  = mirror(temp->left);
		p->left = mirror(temp->right);
		return p;	
			
	}else{
		return NULL;
	}   
}

//CREATING THE MIRROR IMNAGE OF TREE
qnode *BinTree::mirrorNonRecursive(qnode *temp){
	QueueAdt <qnode *>Q;
	if(temp==NULL){
		return temp;
	}else{
		qnode *p,*s;
		Q.enQueue(temp);
		while(!Q.isEmpty()){
			p=Q.deQueue();
		}
		if(p->left==NULL && p->right==NULL){
			s=p->left;
			p->left=p->right;
			p->right=s;
			Q.enQueue(p->left);
			Q.enQueue(p->right);
		}
		else if(p->left==NULL){
			p->left=p->right;
			p->right=NULL;
			Q.enQueue(p->left);
		}else{
			p->right=p->left;
			p->left=NULL;
			Q.enQueue(p->right);
		}
	}
}
//RECURSIVE--CALCULATE THE HEIGHT OF TREE
int BinTree::height(qnode *temp){
 	if(temp!=NULL){
		 return 1+max(height(temp->left),height(temp->right));
	}else{
		return 0;
	}
}

//CALCULATE THE HEIGHT OF TREE
/*
int BinTree::height_nonRec(qnode *temp){
	if(temp==NULL){
		return 0;
	}
	QueueAdt <qnode *>Q;
	int height =0;
	while(1){
		int nodeCount=Q.size();
		if(!Q.isEmpty()){
			return height;
		}
		height++;
		while(nodeCount >0){
			qnode *node=Q.front();;
			Q.deQueue();
			if(node->left!=NULL){
				Q.enQueue(node->left);
			}
			if(node->right!=NULL){
				Q.enQueue(node->right);
			}
			nodeCount--;
		}
	}
}
*/

//DESTRUCTOR
BinTree::~BinTree(){
}
