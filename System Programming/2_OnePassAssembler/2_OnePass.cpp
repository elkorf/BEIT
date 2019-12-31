#include<iostream>
#include<iterator>
#include<map>
#include<string>
#include<fstream>
using namespace std;

int main(){
	map<string,string> M;
	
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
	M.insert(pair<string, string>("start", "01"));
	M.insert(pair<string, string>("end", "02"));
	M.insert(pair<string, string>("origin", "03"));
	M.insert(pair<string, string>("equ", "04"));
	M.insert(pair<string, string>("ltorg", "05"));
	
	//---------------------Declarative Statements--------------
	M.insert(pair<string, string>("dc", "01"));
	M.insert(pair<string, string>("ds", "02"));


	//.insert(pair<string, string>("equ", "00"));  	
	map<string, string>::iterator itr; 
	 	
	
   	cout << "\tKEY\tELEMENT\n"; 
    	for (itr = M.begin(); itr != M.end(); ++itr) { 
        	cout << '\t' << itr->first << '\t' << itr->second << '\n'; 
    	}


	//----------------Reading the Assembly Program file--------
	
	fstream file; 
    	string word,line, t, q, filename; 
 
    	// opening file 
    	file.open("Assembly.txt");
	while(getline(file,line))
	{
		cout<<line<<"\n";
	}
  
    	// extracting words from the file
	cout<<"--------------------------------------------"; 
	file.clear();	
	file.seekg(0,ios::beg);    	
	while (file >> word) 
    	{  
        	cout << word << endl; 
    	} 
	
	return 0; 
}
