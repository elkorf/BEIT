//============================================================================
// Name        : Assignment9.cpp
// Author      : Swapnil Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<string.h>
using namespace std;
#define size 10

//--------STRUCTURE OF STUDENT------------
struct node
{
	char name[20];
	long int tele;
	int flag;
	int link;
}n[size];

//-----CLASS FOR DEFINING THE METHODS-------
class hash1
{
  public:

  //-----------INITIALIZATION WITH NULL VALUES--------
  void initialize()
  {
    for(int i=0;i<size;i++)
    {

    	n[i].link=-1;				//WITH -1
    	n[i].tele=0000000000;		//WITH ZEROS
    	n[i].flag=0;				//WITH ZERO
    	strcpy(n[i].name,"$$$$$$$$");		//WITH '$' SYMBOL

    }
  }

  //-----------GETTING THE NEW NODE--------------
  node getnode()
  {
	  node temp;					//OBJECT
	  cout<<"\nEnter Name : ";
	  cin>>temp.name;

	  cout<<"\nEnter TEL No. : ";
	  cin>>temp.tele;

	  temp.link=-1;
	  return temp;
  }

  //----------INSERTING THE NEW NODE-------------
  node insert(node p,int s)
  {
	 int j,i=0,loc;
	 loc=p.tele%s;
	 loc=j;
	 //-----FINDING THE CHAIN-----------
	 while(i<s && n[j].flag==1)
	 {
		if(n[j].tele%s==p.tele%s)
		{
		   	 break;
		}
	    else		//GO TO NEXT LOCATION
		 {
			 i++;
			 j=(j+1)%s;
		 }

	 }

	 //---------HASH TABLE IS FULL--------
	 if(i==s)
	 {
	   cout<<"\nHash table is full.";
	   return p;
	 }

	 //---------TRAVERSE--------------
	 while(n[j].link!=-1)
	 {
	   j=n[j].link;
	 }
	 loc=j;
	 i=0;

	 while(i<s && n[loc].flag==1)
	 {
	 		loc = (loc+1)%s;
	 		i++;
	 }

	 if(i==s)
	 {
	   cout<<"\nHash table is full";
	   return p;
	 }

	 n[loc]=p;
	 //cout<<loc<<p.link;
	 n[loc].flag=1;

	 if(loc!=j)
	 {
	 	n[j].link=loc;
	 }
	 //n[loc].link=-1;
	 return p;
  }

  //----------DISPLAYING THE RECORDS USING HASH TABLE-------
  void display()
  {
  	  cout<<"  \nSR\t\tNAME\t\tTELEPHONE\t\tLINK\t\tFLAG\n";

	  for(int i=0;i<size;i++)
	  {
		  cout<<" "<<i<<"\t\t";
		  cout<<n[i].name<<"\t\t";
		  cout<<n[i].tele<<"\t\t";
		  cout<<n[i].link<<"\t\t";
		  cout<<n[i].flag<<"\n";
	  }
  }

  //------------SEARCH BY TELEPHONE NUMBER------------
  int serach(int key,int s)
  {
	  int i=0;
	  int loc=key%s;
	  while(i<s && n[loc].flag==1 && (n[loc].tele%s)!=loc)
	  {
		  i++;
		  loc=(loc+1)%s;
	  }
	  //----RECORD NOT FOUND----S
	  if(n[loc].flag!=1 || i==s)
	  {
		  return -1;
	  }
	  //---TRAVERSE TILL-----
	  else
	  {
		  while(loc!=-1)
		  {
			  if(n[loc].tele==key)
			  {
				  return loc;
			  }
			  else
			  {
				  loc=n[loc].link;
			  }
		  }
	  }
	  return -1;
  }

  //------DELETE BY TELEPHONE NUMBER-----------
  int delet(int key,int s){
		int loc=key%s,i; 
		node n1;
		//cout<<n[i].name;
		if(n[loc].link==-1 && n[loc].flag==1){
			cout<<"ff";
			strcpy(n[loc].name,"$$$$$$$$");
			n[loc].link=-1;
			n[loc].flag=0;
			n[loc].tele=00000000;
		}else{
			cout<<"ddd";
			while(n[loc].link!=-1 && n[loc].flag==1)
			{	
				i=n[loc].link;
				n1=n[i];
				n[loc]=n1;	
				loc=n[loc].link;
			}
			cout<<loc;
			strcpy(n[loc+1].name,"$$$$$$$$");
		}
		return 1;
		/*
	  //----RECORD NOT FOUND----S
	  if(n[loc].flag!=1 || i==s)
	  {
		  return -1;
	  }
	  //---TRAVERSE TILL-----
	  else
	  {
		  while(loc!=-1)
		  {
			  if(n[loc].tele==key)
			  {
				  return loc;
			  }
			  else
			  {
				  loc=n[loc].link;
			  }
		  }
	  }*/
  }
  //--------INSERT WITH REPLACEMENT------------
  node insert_with(node p,int s)
  {
	  int loc=p.tele%s;
	  int i=0;
	  if(n[loc].flag==0)
	  {
		  cout<<"hii";
		  n[loc]=p;			//LOCATION IS EMPTY THEN INSERT
		  n[loc].flag=1;	//MAKE FLAG 1
		  return p;
	  }
	  i=0;
	  int j=loc;
	  //---------FINDING THE CHAIN-----------
	  while(i<s && n[j].flag==1)
	  {
		  j=(j+1)%s;
		  i++;
	  }

	  if(i==s)				//HASH TABLE IS FULL
	  {
	  	   cout<<"\nHash table is full";
	  	   return p;
	  }

	  //---------WITH REPLACEMENT--------------
	  if((n[loc].tele)%s!=loc)
	  	{
		  cout<<"hello";
	  		i=(n[loc].tele)%s;
	  		while(n[i].link!=loc)
	  		{
	  			i=n[i].link;
	  		}
	  		n[i].link=n[loc].link;
	  		//FINDING ITS CHAIN UPTO != -1
	  		while(n[i].link!=-1)
	  		{
	  			i=n[i].link;
	  		}
	  		//CREATING CHAIN
	  		n[i].link=j;
	  		n[j].tele=n[loc].tele;
	  		strcpy(n[j].name,n[loc].name);
	  		n[j].flag=1;
	  		n[j].link=-1;
	  		n[loc].tele=p.tele;
	  		n[loc].flag=1;
	  		n[loc].link=-1;
	  		strcpy(n[loc].name,p.name);
	  		return p;
	  	}
	  //IF LOC ALREADY OCCUPIES
	  if(n[loc].tele%s == loc)
	  {
		  cout<<"by";
		  n[j].tele=p.tele;
		  strcpy(n[j].name,p.name);
		  n[j].flag=1;
		  n[j].link=-1;

		  i=loc;
		  while(n[i].link!=-1)
		  {
		   	 i=n[i].link;
		  }
		  n[i].link=j;
		  return p;
	  }


   return p;
  }
};

//--------------MAIN FUNCTION------------------
int main()
{
    hash1 h;				//OBJECT OF CLASS
    h.initialize();		//MAKE EMPTY HASH TABLE
    int ch,d;
	long int key;
    while(1)
    	{
    		cout<<"\n----------Hash function----------";
    		cout<<"\n1.linking without Replacement\n2.linking with Replacement\n3.Exit\nEnter Your Choice : ";
    		cin>>ch;
    		switch(ch)
    		{
    			case 1:
    				do
    				{
    					//---------FOR WITHOUT REPLACEMENT-------------
    				cout<<"\n----------Without Replacement----------";
    				cout<<"\n1.Insert a record\n2.Display \n3.Search record\n4.Delete\n5.Exit\nEnter Your Choice : ";
    				cin>>ch;
    				switch(ch)
    				{
    					case 1:
    						//INSERT
    						node a;
    						a=h.getnode();
    						h.insert(a,size);
    						cout<<"\nInserted successfully...";
    						break;
    					case 2:
    						//DISPLAY
    						h.display();
    						break;
    					case 3:
    						//SEARCH BY TELE. NO.
    						cout<<"\nEnter the Telephone number you want to search : ";
    						cin>>key;
    						d=h.serach(key, size);
    						//IF KEY IS NOT MATCHED
    						if(d==-1)
    						{
    							cout<<"\nRecord not found...";
    						}
    						else		//FOUND
    						{
    							cout<<"\nRecord found...";
    							cout<<"\nNAME\tTELEPHONE\n";
    							cout<<n[d].name<<"\t";
    							cout<<n[d].tele<<"\n";

    						}
    						break;
    				    case 4:
    				    		break;
						
    				    case 5:
    				    		break;		
    				    default:
    				    	cout<<"Invalid Input..!";
    				}
    			}while(ch!=4);
    			break;

    			case 2:
    			    do
    			    {
    			    	cout<<"\n----------With Replacement----------";
    			    	cout<<"\n1.Insert a record\n2.Display \n3.Search record\n4.Delete\n5.Exit\nEnter Your Choice : ";
    			    	cin>>ch;
    			    	switch(ch)
    			    	{
    			    		case 1:
    			    			node a;
    			    			a=h.getnode();
    			    			h.insert_with(a,size);
    			    			cout<<"\nInserted successfully...";
    			    			break;
    			    		case 2:
    			    			h.display();
    			    			break;
    			    		case 3:
    			    			long int key;
    			    			cout<<"\nEnter the Telephone number you want to search : ";
    			    			cin>>key;
    			    			d=h.serach(key, size);
    			    			if(d==-1)		//NOT FOUND
    			    			{
    			    			cout<<"\nRecord not found...";
    			    			}
    			    			else		//RECORD FOUND AND DISPLAYED
    			    			{
    			    				cout<<"\nRecord found...";
    			    				cout<<"\nNAME\t\tTELEPHONE\n";
	    							cout<<n[d].name<<"\t\t";
	    							cout<<n[d].tele<<"\n";
	    						}
	    						break;
	    				    case 4:
								cout<<"\nEnter the Telephone number you want to delete : ";
    			    			cin>>key;
    			    			d=h.serach(key, size);
    			    			if(d==-1)		//NOT FOUND
    			    			{
    			    			cout<<"\nRecord not found...";
    			    			}
    			    			else		//RECORD FOUND AND DISPLAYED
    			    			{
    			    				cout<<"\n\tRecord found...";
    			    				cout<<"\n\t\tNAME\t\tTELEPHONE\n\t\t";
	    							cout<<n[d].name<<"\t\t";
									cout<<n[d].tele<<"\n";
									if(h.delet(key,size)){
										cout<<"\n\tAbove Record is Deleted Successfully...!"<<endl;
										h.display();
									}else{
										cout<<"Error has occured..!";
									}
	    						}
								break;
							case 5:
								break;
	    				    default:
	    				    	cout<<"You have entered the wrong choice...\n";
	    				}
	    			}while(ch!=4);
    			    break;
    			case 3:
    					return 0;
    			default:
    			    	cout<<"You have entered the wrong choice...\n";
    		}
    	}
	return 0;
}

