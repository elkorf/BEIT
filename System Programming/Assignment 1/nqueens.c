#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int chess[100];
int count=0;
int place(int k,int j);
void nqueen(int k,int n);

int output(int n)
{
       
	printf("\nSolution %d:\n",++count);
	
	for(int i=1;i<=n;i++)
	{
		printf("\t%d",i);
	}
	
	for(int i=1;i<=n;i++)
	{
		printf("\n%d",i);
		for(int j=1;j<=n;j++)
		{
			if(chess[i]==j)
				printf("\tQ");
			else
				printf("\t-");
		}
	}
	
	printf("\n");
}

int main()
{
	int n,choice;
	do
	{
		printf("\nMenu\n1.Enter Queens Number\n2.Exit");
		printf("\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			        count=0;
				printf("\nEnter The Number Of Queens Problem:");
				scanf("%d",&n);
				nqueen(1,n);
				break;
			case 2:
				return 0;
				break;
			default:
				printf("Enter Valid Choice");
				break;
		}
	}while(choice!=2);
	return 0;
}

void nqueen(int k,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			chess[k]=i;
		
			if(k==n)
			{
				printf("\nThe Queens Are Placed At:");
				output(n);
				
			}
			else 
				nqueen(k+1,n);
		}
	}
}

int place(int k,int j)
{
	for(int i=1;i<=k-1;i++)
	{
		if((chess[i]==j) || (abs(i-k)==abs(chess[i]-j)))
			return 0;
	}
	return 1;
}