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

struct PoolTable{
	int id;
}poolT[20];

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
	
	fstream file,symbolFile,literalFile,incFile,poolFile,outputFile; 
	int lc=0,count,l=0,ins=0,i=0,s=0,no,symFlag=-1,equ=0,litFlag=0,pool=0,tpool=0,litno=1;
    	string line,filename,word1,word2; 
    	char *word;
 	queue <string> q;
   	// opening file 
 	symbolFile.open("Symbol.txt",fstream::in | fstream::out);
 	literalFile.open("Literal.txt",fstream::in | fstream::out);
 	incFile.open("Incomplete.txt",fstream::in | fstream::out);
 	poolFile.open("Pool.txt",fstream::in | fstream::out);
 	outputFile.open("Output.txt",fstream::in | fstream::out );
    file.open("Assembly.txt");
	file.clear();	
	file.seekg(0,ios::beg);	
	file>>word1;		
	if(word1=="start"){
		it = AD.find(word1);
		//cout<<"[ AD , "<<it->second<<" ]"<<endl;
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
						outputFile<<"\t[ AD , "<<it->second<<" ]";
						if(strcmp(word,"ltorg")==0){
							//pool++;
							poolT[tpool++].id=(++pool);						
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
									outputFile<<"[ C , "<<no<<" ]";
									lc=no;
								}	
							}else{
								cout<<"error";
							}				
						}
						else if(strcmp(word,"end")==0){
							//pool++;
							poolT[tpool++].id=(++pool);						
							if(!q.empty()){
								while(!q.empty()){
									lit[l].literal = q.front();
									q.pop();
									lit[l++].address = lc++;
								}
							}
						}
					}else if(M.count(word)){
						it = M.find(word);
						outputFile<<"[ "<<lc<<" ]"<<" [ IS , "<<it->second<<" ]";
						cout<<"[ "<<lc++<<" ]"<<" [ IS , "<<it->second<<" ]";							
					}
					else if(DL.count(word)){
						it = DL.find(word);
						outputFile<<"[ "<<lc<<" ]"<<" [ DL , "<<it->second<<" ]";
						cout<<"[ "<<lc++<<" ]"<<" [ DL , "<<it->second<<" ]";
					}
					else if(R.count(word)){
						it = R.find(word);
						outputFile<<"[ "<<it->second<<" ]";
						cout<<"[ "<<it->second<<" ]";
					}
					else if(isliteral(word)){
						q.push(word);
						inc[ins].name=word;
						inc[ins++].address=lc;
							outputFile<<"[ L , "<<litno<<" ]";
							cout<<"[ L , "<<litno++<<" ]";		
					}else if(istringstream(word)>>no){
							outputFile<<"[ C , "<<no<<" ]";
							cout<<"[ C , "<<no<<" ]";
					}else{
						if(count>4){
							cout<<"\n Error occured .";
						}else{
							if(count==2 || count==3 || count==4){
								for (int j=0;j<=ins;j++){
									if(inc[j].name==word){
										symFlag=j;
									}	
								}
								if(symFlag==-1){
									symbolFile.open("Symbol.txt",fstream::in | fstream::out);							
									inc[ins].name=word;
									inc[ins].address=lc;
									outputFile<<"[ S , "<<ins<<" ]";
									cout<<"[ S , "<<ins++<<" ]";		
								}else{
									outputFile<<"[ S , "<<symFlag<<" ]";
									cout<<"[ S , "<<symFlag<<" ]";	
								}
							}else{
								sym[s].symbol=word;
								sym[s].address=lc;
								sym[s].len=strlen(word);
								word = strtok(0," ,");
								if(strcmp(word,"equ")==0){
									outputFile<<"\t[ AD , 04 ]";
									cout<<"\t[ AD , 04 ]";
									word = strtok(0," ,");
									if(istringstream(word) >> no){
										outputFile<<"[ C , "<<no<<" ]"; 
										cout<<"[ C , "<<no<<" ]"; 
										sym[s].address=no;
									}
								}else{
									strcpy(s1,line.c_str());
									word = strtok(s1," ");
								}
								s++;	
							}
						}	
						
					}
					word=strtok(0," ,");
				}
				cout<<endl;
				outputFile<<endl;
				count=0;
			}
				 
		}
	}else{	
		cout<<"Error, Must be Start with 'START'";
		return 0;
	}
//------------Printing all the tables----------------		
	cout<<"\n--------------------------------- Literal Table : -----------------------------------------"<<endl;
	int z=0;
	while(z!=l){
		cout<<lit[z].literal<<" "<<lit[z].address<<endl;
		literalFile<<lit[z].literal<<" "<<lit[z++].address<<endl;
	}
	
	cout<<"\n------------------------------Table of incomplete Ins : ------------------------------------"<<endl;
	z=0;
	while(z!=ins){
		cout<<inc[z].name<<" "<<inc[z].address<<endl;
		incFile<<inc[z].name<<" "<<inc[z++].address<<endl;		
	}

	cout<<"\n------------------------------Table of Symbols ------------------------------------"<<endl;
	z=0;
	while(z!=s){
		cout<<sym[z].symbol<<"\t"<<sym[z].address<<"\t"<<sym[z].len<<endl;
		symbolFile<<sym[z].symbol<<"\t"<<sym[z].address<<"\t"<<sym[z++].len<<endl;
	}

	cout<<"\n------------------------------Pool Table ------------------------------------"<<endl;
	z=0;
	while(z!=tpool){
		cout<<"#"<<poolT[z].id<<endl;
		poolFile<<"#"<<poolT[z++].id<<endl;
	}
	symbolFile.close();
	literalFile.close();
	file.close();

//-----------------------------Pass II code-----------------------------------------------
	fstream passI,targetFile;
	passI.open("Output.txt",fstream::in | fstream::out);
	targetFile.open("Target.txt",fstream::in | fstream::out);
	cout<<"\nTarget Code   : "<<endl;
	while(!passI.eof()){					
		while(getline(passI,line))
		{	
			int len=line.length();
			char s1[len+1];
			strcpy(s1,line.c_str());
			word = strtok(s1," ,[]");
			while(word){	
				if(strcmp(word,"AD")==0){
					cout<<" ";
				}else if(strcmp(word,"IS")==0){
					cout<<" ";	
				}else if(strcmp(word,"S")==0){
					word = strtok(0," ,[]");
					istringstream(word) >> no;
					cout<<sym[no].address<<" ";
				}else if(strcmp(word,"L")==0){
					word = strtok(0," ,[]");
					istringstream(word) >> no;
					cout<<lit[no].address<<" ";
				}else if(strcmp(word,"DL")==0){
					word = strtok(0," ,[]");
					if(word=="02"){
						word = strtok(s1," ,[]");
						cout<<" "<<word<<" ";	
					}		
				}else if(strcmp(word,"C")==0){
					word = strtok(0," ,[]");
					istringstream(word) >> no;
					cout<<no<<" ";
				}else{
					
				}
				
				word=strtok(0," ,[]");
			}
			cout<<endl;

		}
	}			
	passI.close();
	targetFile.close();
	return 0; 
}
