#include<iostream>
#include<iterator>
#include<map>
#include<queue>
#include<string>
#include<fstream>
#include<bits/stdc++.h>
#include<cstring>
#include<ctype.h>
using namespace std;
struct TableOfIncomplete{
	string name;
	int address;
}inc[20];

struct symbolTable{
	string symbol;	
	int address,len;	
}sym[20];

struct LiteralTable{
	string literal;
	int address;
}lit[20];

int isliteral(char *word){
	if(word[0]==61)
		return 1;
	return 0;
}

int main(){
	map<string,string> M;
	map<string,string> AD;
	map<string,string> DL;
	map<string, string>::iterator it; 	
	map<string,string> R; 
	//---------------------Mnemonics-------------------------
	M.insert(pair<string, string>("stop", "00"));
	M.insert(pair<string, string>("add", "01"));
	M.insert(pair<string, string>("sub", "02"));
	M.insert(pair<string, string>("mult", "03"));
	M.insert(pair<string, string>("mover", "04"));
	M.insert(pair<string, string>("movem", "05"));
	M.insert(pair<string, string>("comp", "06"));
	M.insert(pair<string, string>("bc", "07"));
	M.insert(pair<string, string>("div", "08"));
	M.insert(pair<string, string>("read", "09"));
	M.insert(pair<string, string>("print","10"));
	
	//---------------------Assembly Directives-----------------
	AD.insert(pair<string, string>("start", "01"));
	AD.insert(pair<string, string>("end", "02"));
	AD.insert(pair<string, string>("origin", "03"));
	AD.insert(pair<string, string>("equ", "04"));
	AD.insert(pair<string, string>("ltorg", "05"));
	
	//---------------------Declarative Statements--------------
	DL.insert(pair<string, string>("dc", "01"));
	DL.insert(pair<string, string>("ds", "02"));

	R.insert(pair<string, string>("areg", "01"));
	R.insert(pair<string, string>("breg", "02"));
	R.insert(pair<string, string>("creg", "03"));
	R.insert(pair<string, string>("dreg", "04"));	
	//.insert(pair<string, string>("equ", "00"));  	
	
	//----------------Reading the Assembly Program file--------
	
	fstream file; 
	int lc=0,count,l=0,ins=0,i=0,s=0,no,symFlag=0,equ=0;
    	string line, filename,word1,word2; 
    	char *word;
 	queue <string> q;
    	// opening file 
    	file.open("Assembly.txt");
	file.clear();	
	file.seekg(0,ios::beg);	
	file>>word1;
	cout<<word1;		
	if(word1=="start"){
		it = AD.find(word1);
		cout<<"[ AD , "<<it->second<<" ]"<<endl;
		file>>word1;
		if(istringstream(word1)>>lc){
			 istringstream(word1)>>lc;
		}else{
			cout<<"Address must be present after start.";
		}
		file.clear();	
		file.seekg(0,ios::beg);
		int j=0;	
		while(!file.eof()){					
			while(getline(file,line))
			{	
				//cout<<line<<endl;

				int len=line.length();
				char s1[len+1];
				strcpy(s1,line.c_str());
				word = strtok(s1," ");
				while(word){
					++count;
					if(AD.count(word)){
						it = AD.find(word);
						cout<<"\t[ AD , "<<it->second<<" ]";
						if(strcmp(word,"ltorg")==0){						
							if(!q.empty()){
								while(!q.empty()){
									lit[l].literal = q.front();
									q.pop();
									lit[l++].address = lc++;
								}
							}else{
								cout<<"pool table is already empty";	
							}								
						}
						else if(strcmp(word,"origin")==0){							
							if(count==1){
								word = strtok(0," ,");
								if(istringstream(word) >> no){
									cout<<"[ C , "<<no<<" ]";
									lc=no;
								}	
							}else{
								cout<<"error";
							}				
						}
						else if(strcmp(word,"equ")==0){							
							if(count==1){
								word = strtok(0," ,");
								if(istringstream(word) >> no){
									cout<<"[ C , "<<no<<" ]";
									lc=no;
								}	
							}else{
								cout<<"error";
							}				
						}
					}else if(M.count(word)){
						it = M.find(word);
						cout<<"[ "<<lc++<<" ]"<<" [ IS , "<<it->second<<" ]";							
					}
					else if(DL.count(word)){
						it = DL.find(word);
						cout<<"[ "<<lc++<<" ]"<<" [ DL , "<<it->second<<" ]";
					}
					else if(R.count(word)){
						it = R.find(word);
						cout<<"[ "<<it->second<<" ]";
					}
					else if(isliteral(word)){
						q.push(word);	
					}else if(istringstream(word)>>no){
							cout<<"[ C , "<<no<<" ]";
					}else{
						if(count>4){
							cout<<"\n Error occured .";
						}else{
							if(count==2 || count==3 || count==4){
								for (int j=0;j<=ins;j++){
									if(inc[j].name==word){
										symFlag=1;
									}	
								}
								if(symFlag==0){
									inc[ins].name=word;
									inc[ins++].address=lc;	
								}

							}else{
								equ=1;
								sym[s].symbol=word;
								sym[s].address=lc;
								sym[s++].len=strlen(word);	
							}
						}	
						
					}
					word=strtok(0," ,");
				}
				cout<<endl;
				count=0;
			}
				 
		}
	}else{	
		cout<<"Error, Must be Start with 'START'";
		return 0;
	}
	
	while(!q.empty()){
		lit[l].literal = q.front();
		q.pop();
		lit[l++].address = lc++;
	}
//------------Printing all the tables----------------		
	cout<<"\n--------------------------------- Literal Table : -----------------------------------------"<<endl;
	int z=0;
	while(z!=l){
		cout<<lit[z].literal<<" "<<lit[z++].address<<endl;
	}
	
	cout<<"\n------------------------------Table of incomplete Ins : ------------------------------------"<<endl;
	z=0;
	while(z!=ins){
		cout<<inc[z].name<<" "<<inc[z++].address<<endl;
	}

	cout<<"\n------------------------------Table of Symbols ------------------------------------"<<endl;
	z=0;
	while(z!=s){
		cout<<sym[z].symbol<<" "<<sym[z].address<<" "<<sym[z++].len<<endl;
	}
	file.close();
	return 0; 
}
