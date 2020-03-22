#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>	
#include <string.h>
#include <sys/types.h>
void sort(int a[],int n)					//Sorting algorithm
{
	int c,d,swap,i;
	for(c=0;c<n;c++)
	{
		for(d=c+1;d<n;d++)
		{
			if(a[c]>a[d])
			{
				swap=a[c];
				a[c]=a[d];
				a[d]=swap;
			}
		}
	}
	printf("\nSorted array :");
	for(i=0;i<n;i++)
	  printf("%d ",a[i]);
}

int main()
{
  int parent_id,child_id,id;
  int p;
  int a[10],n,key,i;
  char str[4],*arg[10];
  printf("\nEnter size of array :");
  scanf("%d",&n);
  for(i=0;i<n;i++)						//Taking array from user
  {
  	printf("Enter %dth element :",i+1);
  	scanf("%d",&a[i]);
  }
  id=getpid();
  
  printf("In parent process.. ID->%d\n",id);
  printf("Sorting numbers ...\n");
  sort(a,n);
  //printf("\nSorting completed !");
  printf("Invoking fork ...\n");
  id=fork();
  printf("Fork called !\n");
  if(id==0)
  {
   	 child_id=getpid();					//child
  	 printf("Entered in child .. ID-> %d\n",child_id);
  	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
		sprintf(str,"%d",a[i]);				//Convering to string
		arg[i]=malloc(sizeof(str));
		strcpy(arg[i],str);
	}
	arg[i]=NULL;
	printf("Executing execv Statment\n execv(./2b2,arg,NULL);\n\n");
	execve("./2b2",arg,NULL);				//Calling function
	printf("execve Completed\n");
	
	printf(" Now Child Exits\n\n");
	
  	 printf("Child is now Completed!! \n ");
  }
  else
  {								//parent
  	printf("Entered in parent... Now waiting!!\n\n");
    	sleep(10);
  	printf("Parent is now executed and exited !\n");
  }
  
  
	return 0;
}
