#include <stdio.h>
#include <conio.h>
void main()
{
	int i, j = 1, k = 2, flag;
	for(int i = 0 ;i <= 4 ; i++)
	{
		k = i + j * k;
	}
	flag = 55;
	if(flag == 10)
		printf("Hello all");
	getch();
}
