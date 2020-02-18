#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include<cstring>
#include<vector>
#include<ctype.h>
using namespace std;

struct UST{
	char Class[3];
	string token;
	int index;
};

struct TT{
	int index;
	string token;
};

struct IDNT{
	int index;
	string token;	
};

struct LT{
	int index;
	string token;
};

void createTables(vector<string>w){
	vector<string>::iterator it,ti;
	string keywords[] = {"main()","int","{","}"};
	int len=sizeof(keywords)/sizeof(keywords[0]);
	vector<string> terminals(keywords, keywords+len);
	for(it=w.begin();it!=w.end();it++){
		if(ti = find(terminals.begin(), terminals.end(),*it)){
			cout<<"found at : "<<ti - keywords.begin();
		} 
	}
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
		if(c==' '){
			w.push_back(word);
			word.clear();
		}
		word.push_back(c);			
	}
	w.push_back(word); 
	file.close();		
	createTables(w);
	return 0;
}
