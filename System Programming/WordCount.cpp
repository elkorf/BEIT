#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main(){
	int c=0,sc=0,sp=0,num=0,ap=0,w=0;
	string word;
	char ch;
	fstream fi;
	fi.open("Assembly.txt");
	while(!fi.eof()){
		fi.get(ch);
		if(ch == ' '){
			sc++;
		}
		else if(isdigit(ch)){
			num++;
		}
		else if(isalpha(ch)){
			ap++;
		}	
		else if(ch >=33 and ch <=47 or ch>=58 and ch<=64){
			sp++;	
		}
					
	}
	fi.clear();
	fi.seekg(ios::beg);
	while(fi >> word){
		w++;
	}
	fi.close();
	cout<<"Number of Spaces  : "<<sc<<endl;
	cout<<"Number of Special symbols  : "<<sp<<endl;
	cout<<"Number of Numeric Values :  "<<num<<endl;
	cout<<"NUmber of Alphabets  : " <<ap<<endl;
	cout<<"Number of Words : "<<w<<endl;
	return 0;
}
