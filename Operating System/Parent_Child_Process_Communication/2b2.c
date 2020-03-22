#include<stdio.h>

#include <stdlib.h>
void main(int argc,char *argv[])				//Searching element
{
	int key,i,arr[10],l,u,mid,f=0;
	printf("Number of argc :%d\n",argc);
	for(i=0;i<argc;i++)
	{
	 arr[i]=atoi(argv[i]);
	}
	printf("Enter number to search :");
	scanf("%d",&key);
	l=0,u=argc-1;
	while(l<=u)
	{
		mid=(l+u)/2;
		if(key<arr[mid])
		 u=mid-1;
		else if(key>arr[mid])
		 l=mid+1;
		else if(key==arr[mid])
		{
	   	 f=1;
	   	 break;
	   	}
		
	}
	
	if(f==0)
		printf("%d not found!!\n",key); 
	else
	{
		printf("%d found at %d\n",key,mid);
		//printf("nhelooo\n");
	}	
	
}
