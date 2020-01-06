#include<iostream>
#include<iterator>
#include<map>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<cstring>
#include<ctype.h>
using namespace std;

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
	
	FILE *file; 
    string word,line, t, q, filename; 
 	char label[10],opcode[10],operand[10];
 	int start,lc=0,bit=0;    	
 	    	// opening file 
    file=fopen("Assembly.txt","r");
while(fscanf(file,"%s%s%s",label,opcode,operand)==1){
	if(strcmp(label,"start")==0 && atoi(opcode) && !bit)
	{	
		start = atoi(opcode);
		string label1 = label;
		it = AD.find(label1);
		cout<<"[ AD , "<<it->second<<" ]";
		lc=start;
		bit=1;

	}
	if(bit){
		{
			cout<<label<<" "<<opcode<<" "<<operand;
		}
	}
}
	/*file>>word;	
	if(word == "start"){
		it = AD.find(word);
		cout<<"[ AD , "<<it->second<<" ]";
		file.clear();	
		file.seekg(0,ios::beg);	
		while(!file.eof()){					
			while(file>>word)
			{	
				//char *token = strtok(str, " ");
					if(word==" " or word==","){
						continue;
					}else{
						
						if(AD.count(word)){
							it = AD.find(word);
							cout<<"[ AD , "<<it->second<<" ]";							
						}else if(M.count(word)){
							it = M.find(word);
							cout<<"[ IS , "<<it->second<<" ]";						
						}else if(DL.count(word)){
							it = DL.find(word);
							cout<<"[ DL , "<<it->second<<" ]";
						}
					}	
				
				
			}
		}
	}else{	
		cout<<"Error, Must be Start with 'START'";
	}*/

	fclose(file);
	return 0; 
}
