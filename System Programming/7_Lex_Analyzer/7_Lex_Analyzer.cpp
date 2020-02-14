#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include<cstring>
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

int main(){
	string line;
	char *word;
	fstream file;
	file.open("Input.c",ios::in);
	while(getline(file,line)){
		int len = line.length();
		char w[len+1];
		strcpy(w,line.c_str());
		word = strtok(w," ();");		
		while(word){
			cout<<word<<"\n";
			word=strtok(0," ();");
		}	
	}	
	file.close();		
	return 0;
}
