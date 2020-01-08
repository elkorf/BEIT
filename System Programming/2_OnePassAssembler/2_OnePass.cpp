#include<iostream>
#include<iterator>
#include<map>
#include<string>
#include<fstream>
#include<bits/stdc++.h>
#include<cstring>
#include<ctype.h>
using namespace std;
struct symbolTable{
	int id,add,len;
	string name;	
}s[10];

int isliteral(string word){
	return 0;
}
int main(){
	map<string,string> M;
	map<string,string> AD;
	map<string,string> DL;
	map<string, string>::iterator it; 	

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


	//.insert(pair<string, string>("equ", "00"));  	
	
	//----------------Reading the Assembly Program file--------
	
	fstream file; 
	int lc=0;
    	string word,line, t, q, filename; 
 
    	// opening file 
    	file.open("Assembly.txt");
	file.clear();	
	file.seekg(0,ios::beg);	
	file>>word;	
	if(word == "start"){
		it = AD.find(word);
		cout<<"[ AD , "<<it->second<<" ]"<<endl;
		file>>word;
		if(istringstream(word)>>lc){
			 //istringstream(word)>>lc;
			 cout<<"lc --> "<<lc<<endl;	
		}else{
			cout<<"Address must be present after start.";
		}
		file.clear();	
		file.seekg(1,ios::beg);	
		while(!file.eof()){					
			while(getline(file,line))
			{	
				istringstream ss(line);
				do {  
        				ss >> word;
        				//cout<<word<<"\t\t"; 
					if(AD.count(word)){
						it = AD.find(word);
						cout<<"[ AD , "<<it->second<<"]";							
					}else if(M.count(word)){
						it = M.find(word);
						cout<<"[ IS , "<<it->second<<" ]";						
					}else if(DL.count(word)){
						it = DL.find(word);
						cout<<"[ DL , "<<it->second<<" ]";
					}else if(isliteral(word)){
						//cout<<"ok";
					}else{
						//symbolTable *s;
						s->id=1;
						s->name=word;
						s->len=word.size();
						s->add=lc;	
						//add into symbol table
							
					}
				}while (ss);
				cout<<endl; 
			}
				 
		}
	}else{	
		cout<<"Error, Must be Start with 'START'";
	}
	
	for(int i=0;i<10;i++){
		cout<<s->name<<endl;
	}
	file.close();
	return 0; 
}