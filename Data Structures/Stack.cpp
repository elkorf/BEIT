/*========================================================================
Roll No		  : 23347		Batch: G11 	Class: SEIT 11
Name		  : Swapnil Gokool Patil
Assignment No	  : 1
Problem Statement : 
 =========================================================================*/

#include <iostream>
#include <string.h>
#include "StackAdt.h"
#include "StackAdt.cpp"
using namespace std;

//------------------CLASS FOR METHODS--------------------------------
class Expression{
	
	private:

	public:
		void getExp(char *);
		int getPriority(char);
		int operation(int ,int ,int );
		void infixToPostfix(char *,char *);
		void infixToPrefix(char *,char *);
		void strReverse(char *);
		void prefixEval(char *);
		void postfixEval(char *);
		bool isRightAssociative(char );
};

//------------GETTING EXPRESSION FROM USER----------------------------
void Expression::getExp(char *exp){
	cout<<"Enter the Expression : ";
	cin>>exp;
	int i=0,c1=0,c2=0;
	/*do
	{
		if(*(exp+i)=='('){
		}
		if(*(exp+i)==')'){
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
	while(*(exp+i)!='\0')
	{
		if((!isalnum(*(exp+i)) and !isalnum(*(exp+(i+1)))) or (isalpha(*(exp+i)) and isalpha(*(exp+(i+1)))) or !isalnum(*(exp+0)) or !isalnum(*(exp+(len-1)))){
			cout<<"Enter the Expression again : ";
			cin>>exp;
			i=0;
		}
		else{
			i++;
		}
	}*/
}

//------CHECKING ASSOCIATIVE OF OPERATOR-----------------------------------------
bool Expression::isRightAssociative(char ch){
	if(ch=='^' or ch=='!')
		return true;
	return false;
}

//-----REVERSING THE EXPRESSION FOR PREFIX OPERATIONS--------------------------
void Expression::strReverse(char *exp){		
	int i=0;
	StackAdt<char> s;
	while(*(exp+i)!='\0'){				//TILL THE END OF EXPRESSION
		if(*(exp+i)=='('){				//PUSHING ELEMENTS IN STACK FOR REVERSING				
			s.push(')');
		}
		else if(*(exp+i)==')'){
			s.push('(');
		}else{
			s.push(*(exp+i));
		}
		i++;
	}
	i=0;				
	while(!s.isEmpty()){				//POPING THE ELEMENTS FROM STACK
		*(exp+i)=s.pop();
		i++;
	}
}

//--------------FOR ASSIGNING THE PRIORITY-------------------------------
int Expression ::getPriority(char x){
	//cout<<x;
	switch(x){
		case '+':
		case '-':
			return 1;			//LOWEST PRIORITY
			break;
		case '*':
		case '/':
		case '%':
			return 2;			//MIDDLE PRIORITY
			break;
		case '^':
			return 3;			//HIGHEST PRIORITY
			break;
		case '!':
			return 4;
			break;		
		default:
			return 0;	
	}
}

//--------FOR PERFORMING OPERATIONS BASED ON OPERATOR--------------
int Expression::operation(int a,int b,int ch){
	switch (ch){
		case '*':
			return(a * b);				//MULTIPLICATION
			break;
		case '/':
			return(b / a);				//DUVISION
			break;
		case '+':
			return(b + a);				//ADDITION
			break;
		case '-':
			return(b - a);				//SUBSTRACION
			break;
		case '%':
			return(b % a);				//MODULUS
			break;
		case '^':
			return(b ^ a);				//POWER OF
			break;
		case '!':
			return(!a);					//INVERTING
			break;
	}
}

//--------CONVERSION OF INFIX TO POSTFIX--------------
void Expression::infixToPostfix(char *exp,char *result){
	
	int i=0,k=0;
	StackAdt<char> s;					//STACK OBJECT FOR CHARACTERS
	
	while(*(exp+i)!='\0'){				//TILL END OF EXP
		if(*(exp+i)=='('){				//SIMPLY PUSH
			s.push(*(exp+i));
			i++;
		}
		else if(*(exp+i)==')'){			//POP TILL ( OCCURS	
			while(s.peep()!='('){
				*(result+k)=s.pop();
				k++;
			}
			s.pop();
			i++;
		}
		else if(isalnum(*(exp+i))){		//IF NUMBER OF ALPHABET STORE IN TEMP VAR
			*(result+k)=(*(exp+i));
			k++;i++;
		}
		else{
			if(s.isEmpty()){			//IF STACK IS EMPTY
				s.push(*(exp+i));
				i++;
			}							//SAME PRIORITY CHECKING
			else if(getPriority(*(exp+i))==getPriority(s.peep())){
				if(isRightAssociative(*(exp+i))){
					s.push(*(exp+i));
					i++;
				}
				else{
					int c=getPriority(s.peep());
					cout<<c<<endl;
					int d=getPriority(*(exp+i));
					while(c==d and !s.isEmpty()){	//SAME PRIORITY
						*(result+k)=s.pop();
						k++;
						//int c=getPriority(s.peep());
					}
					s.push(*(exp+i));
					i++;
				}	
			}
			else if(getPriority(s.peep())>getPriority(*(exp+i))){
					int c=getPriority(s.peep());
					cout<<c<<endl;
					int d=getPriority(*(exp+i));
					while(c>d and !s.isEmpty()){ 	//HIGHER PRIORITY
						*(result+k)=s.pop();
						//int c=getPriority(s.peep());
						k++;
					}
					s.push(*(exp+i));
					i++;
			}
			else{
					s.push(*(exp+i));				//SIMPLY PUSH
					i++;
			}
		}
		
	}
	
//----------PRINTING THE FINAL EXPRESSION-----------------------
	while(!s.isEmpty()){
		*(result+k)=s.pop();
		k++;
	}
	cout<<result;
}

//-----------INFIX TO PREFIX CONVERSION--------------------------
void Expression::infixToPrefix(char *exp,char *result)
{
	
	StackAdt<char> s;							//STACK OBJECT
	strReverse(exp);							//REVERSING THE STRING
	int i=0,k=0,count=0;
	while(*(exp+i)!='\0')						//TILL END OF EXPRESSION
	{
		if(*(exp+i)=='(')
		{
			count++;
			s.push(*(exp+i));
			i++;
		}
		else if(*(exp+i)==')')					//IF )-> SIMPLY POP TILL (
		{
			count++;
			while(s.peep()!='(')
			{
				*(result+k)=s.pop();
				k++;
			}
			s.pop();
			i++;
		}
		else if(isalnum(*(exp+i)))				 //IF NUMBER OR ALPHBET
		{
			*(result+k)=(*(exp+i));
			k++;i++;
		}
		else{
			if(s.isEmpty()){
				s.push(*(exp+i));
				i++;
			}									//SAME PRIORITY
			else if(getPriority(*(exp+i))==getPriority(s.peep())){
				if(isRightAssociative(*(exp+i))){
					s.push(*(exp+i));
				}
				else{
					int c=getPriority(s.peep());
					int d=getPriority(*(exp+i));
					while(c==d and !s.isEmpty()){	//SAME PRIORITY
						*(result+k)=s.pop();
						k++;
					}
					s.push(*(exp+i));
				}
				i++;		
			}
			else if(getPriority(s.peep())>getPriority(*(exp+i))){
					int c=getPriority(s.peep());
					int d=getPriority(*(exp+i));
					while(c>d and !s.isEmpty())		//HIGER PRIORITY
					{
						*(result+k)=s.pop();
						k++;
					}
					s.push(*(exp+i));
					i++;
			}
			else{
					s.push(*(exp+i));
					i++;
			}
		}
		
	}
	
//-----------------PRINTING THE RESULT----------------------------
	while(!s.isEmpty()){
		*(result+k)=s.pop();
		k++;
	}
	strReverse(result);			//AGAIN REVERSING THE EXP FOR PREFIX
	cout<<result;
}

//---------------POSTFIX EVALUATION----------------------------- 	
void Expression::postfixEval(char *exp){
	int i,a,b,val,*var2,j=0,k=0,z=0;
	char ch,*var1;
	StackAdt<int> s1;			//OBJECT OF STACK OF INTEGER
	var2=new int;				//FOR STORING THE OPRANDS
	var1=new char;				//FOR STORING THEIR VALUES
	
	for (i = 0 ; *(exp+i) != '\0'; i++){//CHECKING IT IS ALPHABET OF OPERATOR
		ch = *(exp+i);
		if (isalpha(ch)){
			//GETTING THE VALUE OF ALPHABET FROM USER
			if(k==0){
				*(var1+k)=ch;
				cout<<"Enter the value of "<<ch<<":";
				cin>>*(var2+k);	
				s1.push(*(var2+k));
				k++;
			}
			//IF THE VARIABLE OCCURS AGAIN
			else{
				for(j=0;j<=k;j++){
					if(*(var1+j)==ch){
						s1.push(*(var2+j));
						z++;
						break;
					}
				}
				if(z==0){
					*(var1+k)=ch;
					cout<<"Enter the value of "<<ch<<":";
					cin>>*(var2+k);	
					s1.push(*(var2+k));
					k++;
				}
			}	
		}
		
//----PERFORM THE OPERATION ON TOP MOST ELEMENTS ON STACK AND AGAIN PUT INTO STACK
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch=='%' || ch=='^' || ch=='!'){
			a = s1.pop();
			b = s1.pop();
			val=operation(a,b,ch);
			s1.push(val);
		}
	}
	//PRINTING THE RESULT SIMPLY POP FROM INT STACK
	cout<<" \n Result of expression evaluation :"<<s1.pop();
}

//------EVALUATION OF PREFIX EXPRESSION----------------------
void Expression::prefixEval(char *exp){
	strReverse(exp);
	StackAdt<int> s1;					//STACK OBJECT FOR INT DATA
	int i,a,b,val,*var2,j=0,k=0,z=0;
	char ch,*var1;
	var2=new int;
	var1=new char;
	for (i = 0 ; *(exp+i) != '\0'; i++){//TILL THE END OF EXPRESSION
		ch = *(exp+i);
		if (isalpha(ch)){				//GETTING THE VALUE OF VAR FROM USER
			if(k==0){
				*(var1+k)=ch;
				cout<<"Enter the value of "<<ch<<":";
				cin>>*(var2+k);	
				s1.push(*(var2+k));
				k++;
			}
			//IF THE VAR IS ALREADY OCCURS
			else{
				for(j=0;j<=k;j++){
					if(*(var1+j)==ch){
						s1.push(*(var2+j));
						z++;
						break;
					}
				}
				//GETTING VALUE FOR VAR FROM USER
				if(z==0){
					*(var1+k)=ch;
					cout<<"Enter the value of "<<ch<<":";
					cin>>*(var2+k);	
					s1.push(*(var2+k));
					k++;
				}
			}	
		}
		//-----OPERATIONS BASED OF OPERATOR---------
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch=='%' || ch=='^' || ch=='!'){
			b = s1.pop();
			a = s1.pop();
			val=operation(a,b,ch);
			s1.push(val);
		}
	}
	//PRINTING THE RESULT SIMPLY POP FROM INT STACK
	cout<<" \n Result of expression evaluation :"<<s1.pop();
}
int main() {
	Expression e;
	char *exp,*result;
	//INITIALIZING THE ARRAYS WITH MAX SIZE 20 USING NEW KEYWORD
	exp= new char(20);
	result=new char(20);
	int ch,a,b;

	while(1){
		cout<<"\n1.Expression Conversion\n2.Expression Evaluation\n3.Exit\nEnter Your Choice : ";
		cin>>ch;
		switch(ch){
			case 1:
			//-----------FOR EXPRESSION CONVERSION-----------
				cout<<"\n\t1.Infix to Prefix\n\t2.Infix to Postfix\n\t3.exit\n\tEnter Your Choice : ";
				cin>>a;
				switch(a){
					case 1:
					//----INFIX TO PREFIX EXPRESSION CONVERSION----
						e.getExp(exp);
						e.infixToPrefix(exp,result);
						break;
					case 2:
					//----INFIX TO POSTFIX EXPRESSION CONVERSION----
						e.getExp(exp);
						e.infixToPostfix(exp,result);
						break;
					case 3:
					//EXIT
						return 0;
						break;
					default:
						cout<<"\n\tInvalid Choice!!!";
						break;
				}
				break;
			case 2:
			//---------FOR EXPRESSION EVALUATION-----------
				cout<<"\n\t1.Prefix Evaluation\n\t2.Postfix Evaluation\n\t3.exit\n\tEnter Your Choice : ";
				cin>>b;
				switch(b){
					case 1:
					//----PREFIX EXPRESSION EVALUATION------
						e.getExp(exp);
						e.prefixEval(exp);
						break;
					case 2:
					//----POSTFIX EXPRESSION EVALUATION------
						e.getExp(exp);
						e.postfixEval(exp);
						break;
					case 3:
					//EXIT
						return 0;
						break;
					default:
						cout<<"\n\tInvalid Choice!!!";
						break;
				}
				break;
			case 3:
			//EXIT
				return 0;
			default :
				cout<<"\nInvalid Choice!!!";
		}
	}
	return 0;
}
