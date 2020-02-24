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
	/*for(it=w.begin();it!=w.end();it++){
		if(ti = find(terminals.begin(), terminals.end(),*it)){
			cout<<"found at : "<<ti - keywords.begin();
		} 
	}*/
}

int main(){
	char c;
	string word;
	vector<string> w;
	vector<string> ::iterator it;
	int i=0;
	fstream file;
	file.open("input.c",ios::in);
	while(!file.eof()){
		c=file.get();		
		if(c==' ' or c=='"' or c=='\n'){
			w.push_back(word);
			word.clear();
		}else if(c=='{' or c=='}' or c=='(' or c==')'){
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
	for(auto i=w.begin();i!=w.end();++i){
		cout<<*i<<" ";
	}
	file.close();
	cout<<w.size();	
	createTables(w);
	return 0;
}
