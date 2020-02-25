#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include<cstring>
#include<vector>
#include<ctype.h>
#include<algorithm>
#include<cstring>
#include<ctype.h>
#include<string>
using namespace std;

struct UST{
	char Class[3];
	string token;
	int index;
};

struct TT{
	string token;
};

struct IDNT{
	string token;	
};

struct LT{
	int token;
};

void createTables(vector<string>w){
	int t=0,u=0,id=0,l=0;
	vector<string>::iterator it,ti;
	UST ust[10];
	TT tt[10];
	IDNT idnt[10];
	LT lt[10];
	int number;
	
	string keywords[] = {"int","float","if","else","for","while","do","(",")","{","}","printf","scanf"};
	int len=sizeof(keywords)/sizeof(keywords[0]);
	
	vector<string> terminals(keywords, keywords+len);
	
	for(it=w.begin();it!=w.end();it++){
		//string s(*it);
		if(find(terminals.begin(), terminals.end(),*it) !=terminals.end()){
			ti = find(terminals.begin(), terminals.end(),*it);
			tt[t++].token=*it;
			//cout<<"found at : "<<ti-terminals.begin();
		}else if(stringstream(*it)>>number){
			lt[l++].token=number;
		}else{
			idnt[id++].token = *it;	
		}
	}
	
	cout<<"\nLiteral table\n";
	for(int i=0;i<l;++i){
		cout<<"#"<<i<<"\t"<<lt[i].token<<endl;
	}
	cout<<"\nIdentifier table";
	/*for(int i=0;i<10;++i){
		//cout<<"Literal table";
		cout<<"#"<<i<<idnt[i].token<<endl;
	}*/	
}
int main(){
	char c;
	string word;
	vector<string> w;
	vector<string> ::iterator it;
	int i=0;
	fstream file;
	file.open("Input.c",ios::in);
	while(!file.eof()){
		c=file.get();		
		if(c==' ' or c=='"' or c=='\n' or c=='\t' or c=='='){
			w.push_back(word);
			word.clear();
		}else if(c=='{' or c=='}' or c=='(' or c==')' or c==';'){
			if(word.empty()==false){
				w.push_back(word);
				word.clear();
			}
			string s(1,c);
			w.push_back(s);
			
		}else{
			word.push_back(c);
		}			
	}
	w.push_back(word); 
	for(it=w.begin();it!=w.end();++it){
		cout<<*it<<" ";
	}
	
	file.close();
	cout<<w.size();	
	createTables(w);
	return 0;
}
