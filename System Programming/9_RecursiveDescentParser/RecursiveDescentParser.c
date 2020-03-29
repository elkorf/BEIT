#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char input[1024];
int i,error,len;
void S();
void E();
void T();

void main()
{
	i = 0;
	error = 0;
	
	printf("\nEnter string :");
	fgets(input, sizeof(input), stdin);
	
	int l1 = strlen(input);
	S();
	if(strlen(input)-1 == i && error == 0)
		printf("\nAccepted..");
	else
		printf("\nRejected..");
}

void S()
{
	E();
	T();
	if(input[i] != ';')
		error = 1;
	else if(input[i] == ';')
		i++;			
}

int isInt(char *ip)
{
	if(ip[0] == 'i' && ip[1] == 'n' && ip[2] == 't')
		return 1;
	return 0;
}

int isFloat(char *ip)
{
	if(ip[0] == 'f' && ip[1] == 'l' && ip[2] == 'o' && ip[3] == 'a' && ip[4] == 't')
		return 1;
	return 0;
}

int isChar(char *ip)
{
	if(ip[0] == 'c' && ip[1] == 'h' && ip[2] == 'a' && ip[3] == 'r')
		return 1;
	return 0;
}

int match(char ip[])
{
	if(isInt(ip))
		return 3;
	else if(isFloat(ip))
		return 5;
	else if(isChar(ip))
		return 4;
	else
		return 0;
}

void E()
{
	len = match(input);
	if(len)
		i = len+1;
	else
		error = 1;
}

void T()
{
	if(isalpha(input[i]))
	{
		while(isalnum(input[i]))
			i++;
		if(input[i] == ',')
		{
			i++;
			T();
		}
		else if(isalpha(input[i]))
		{
			while(isalpha(input[i]))
				i++;
		}
	}
	else
		error = 1;
}
