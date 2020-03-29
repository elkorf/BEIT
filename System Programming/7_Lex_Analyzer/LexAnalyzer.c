#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int count = 0;

char sym_list[] = { '#', '<', '>', '{', '}', '(', ')', '+', '-', '*', '/',  '\'', ',', ';', '&', '=', '[' , ']' }; //19 Elements

struct IDN
{
	char *name;
	int srno;
}IDN;

struct LTR
{
	char *name;
	int srno;
}LTR;

struct terminal
{
	char *name;
	int srno;
}TRN;

struct UST
{
	char *class, *sym;
	int srno;
}UST;

void init(struct terminal TRN[])
{
	FILE *fp;
	fp = fopen("terminal.txt","r");
	
	for(int i=0;i<25;i++)
	{
		TRN[i].name = (char *)malloc(sizeof(char));
		fscanf(fp, "%d\t%s", &TRN[i].srno, TRN[i].name);
	}
	
	fclose(fp); 
}

void alloc(struct IDN IDN[], struct LTR LTR[], struct UST UST[])
{
	for(int i=0;i<20;i++)
	{
		IDN[i].name = (char *)malloc(sizeof(char));
		LTR[i].name = (char *)malloc(sizeof(char));
	}
	for(int i=0;i<50;i++){
		UST[i].class = (char *)malloc(sizeof(char));
		UST[i].sym   = (char *)malloc(sizeof(char));	
	}
}

char find_sym(char ch)
{
	for(int i=0;i<19;i++)
	{
		if(sym_list[i] == ch)
			return 'T';
	}
	return 'F';
}

int find_terminal(struct terminal TRN[] ,char* ch)
{
	for(int i=0;i<25;i++)
	{
		if(!strcmp(TRN[i].name, ch))
			return i;
	}
	return -1;
}

int find_idn(struct IDN IDN[], char* ch)
{
	for(int i=0;i<20;i++)
	{
		if(!strcmp(IDN[i].name, ch))
			return i;
	}
	return -1;
}

int find_ltr(struct LTR LTR[], char* ch)
{
	for(int i=0;i<20;i++)
	{
		if(!strcmp(LTR[i].name, ch))
			return i;
	}
	return -1;
}

void performOP(struct terminal TRN[], struct IDN IDN[], struct LTR LTR[], struct UST UST[])
{
	FILE *ip, *op;
	FILE *counter;
	
	ip = fopen("input.c","r");
	op = fopen("output.txt", "w");
	
	counter = fopen("counter.txt","r");
	fscanf(counter, "%d", &count);
	fclose(counter);
	
	counter = fopen("counter.txt","w");
	count = count + 1;
	fprintf(counter, "%d", count);
	
	fprintf(op, "Number of times program run : %d\n", count);
	fprintf(op, "----------------------------------\n");
	char *c		= (char *)malloc(sizeof(char));
	char *c1 	= (char *)malloc(sizeof(char));
	char *string 	= (char *)malloc(sizeof(char));
	char *temp 	= (char *)malloc(sizeof(char));
	char *numString = (char *)malloc(sizeof(char));
	char *spec_sym 	= (char *)malloc(sizeof(char));
	
	int i = 0, look = 0, identifier_index = 0, literal_index = 0, search_sym = 0;
	
	*temp		= '\0';
	*string 	= '\0';
	*numString	= '\0';
	*spec_sym	= '\0';
	*c1 		= '\0';
	*c		= '\0';
	
	printf("INDEX\t  KEYOWORD\tCLASS\n");
	printf("----------------------------------\n");
	fprintf(op, "INDEX\t  KEYOWORD\tCLASS\n");
	fprintf(op, "----------------------------------\n");
	
	*c = fgetc(ip);
	while(*c != EOF)
	{
		if(look)
		{
			if(*c == '+' || *c == '-' || *c == '=')
			{
				strcat(spec_sym, c);
				search_sym = find_terminal(TRN, spec_sym);
				if(search_sym != -1){
					printf("%2d%14s%12s\n", search_sym+1, spec_sym, "LTR");
					fprintf(op, "%2d%14s%12s\n", search_sym+1, spec_sym, "LTR");
				}
				else
					printf("NOT FOUND\n");
				*spec_sym = '\0';
				*c = fgetc(ip);
				look = 0;
				continue;
			}
			else
			{
				search_sym = find_terminal(TRN, spec_sym);
				if(search_sym != -1){
					printf("%2d%14s%12s\n", search_sym+1, spec_sym, "LTR");
					fprintf(op, "%2d%14s%12s\n", search_sym+1, spec_sym, "LTR");
				}
				else
					printf("NOT FOUND\n");
			}
			look = 0;
			*temp		= '\0';
			*string 	= '\0';
			*numString	= '\0';
			*spec_sym	= '\0';
			*c1 		= '\0';
		}
		
		if(find_sym(*c) == 'T')
		{
			strcat(spec_sym, c);
			look = 1;
		}
		
		if(isdigit(*c))
		{
			*temp 	= '\0';
			*string = '\0';
			
			while(isdigit(*c))
			{
				strcpy(temp, c);
				strcat(numString, temp);
				*c = fgetc(ip);
				
				if(!isdigit(*c) && find_sym(*c) == 'T') {
					look = 1;
					strcat(spec_sym, c);
				}
			}
			/*INSERT "int" in LITERAL table*/
			int search_ltr = find_ltr(LTR, numString);
			if(search_ltr == -1)
			{
				strcpy(LTR[literal_index].name, numString);
				LTR[literal_index].srno = literal_index;
				printf("%2d%14s%12s\n", literal_index+1, numString, "LTR");
				fprintf(op, "%2d%14s%12s\n", literal_index+1, numString, "LTR");
				literal_index++;
			}
			else{
				printf("%2d%14s%12s\n", search_ltr+1, numString, "LTR");
				fprintf(op, "%2d%14s%12s\n", search_ltr+1, numString, "LTR");
			}
			*numString = '\0';
		}
		if(!isalpha(*c) && *string != '\0' && !isdigit(*string) && *c != 46)
		{
			/*SEARCH for KEYWORD in TERMINAL table and get the INDEX from terminal table*/
			int index = find_terminal(TRN, string); 
			if(index != -1)
			{
				printf("%2d%14s%12s\n", index+1, string, "TRN");	
				fprintf(op, "%2d%14s%12s\n", index+1, string, "TRN");
			}
			/*IF NOT FOUND THEN IT MUST BE IDENTIFIER. So, INSERT it in identifier table*/
			else
			{
				int search_idn = find_idn(IDN, string);
				if(search_idn == -1)
				{
					strcpy(IDN[identifier_index].name, string);
					IDN[identifier_index].srno = identifier_index;
					printf("%2d%14s%12s\n", identifier_index+1, string, "IDN");
					fprintf(op, "%2d%14s%12s\n", identifier_index+1, string, "IDN");
					identifier_index++;					
				}
				else{
					printf("%2d%14s%12s\n", search_idn+1, string, "IDN");
					fprintf(op, "%2d%14s%12s\n", search_idn+1, string, "IDN");
				}
			}
			*string = '\0';
		}
		if( *c == ' '|| *c == 10 || *c == 9 )
		{
			*c = fgetc(ip);
			*string = '\0';
			*temp = '\0';
			*numString = '\0';
			continue;
		}
		if(isalpha(*c) || *c == '.')
		{
			strcpy(temp, c);
			strcat(string, temp);	
		}
	
		*c = fgetc(ip);
	}
	fprintf(op, "----------------------------------");
	fclose(ip);
	fclose(op);
	fclose(counter);
}

int main()
{
	struct terminal TRN[50];
	struct IDN IDN[20];
	struct LTR LTR[20];
	struct UST UST[70];
	
	init(TRN);
	alloc(IDN, LTR, UST);
	performOP(TRN, IDN, LTR, UST);
	return 0;
}
