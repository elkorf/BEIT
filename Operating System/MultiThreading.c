#include<stdio.h>
#include<pthread.h>
#define MAX 10
#define MAX_TH 10
int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
int count=1;

void *multi(void* arg) 
{ 
 	int return_val,row,col,k,i,z;
 	int *rcArg;
 	return_val=0;
 	rcArg=(int *)arg;
 	row=rcArg[0];
 	col=rcArg[1];
 	k=rcArg[2];
 	printf("\n\nThread %d-%d joined! ",row+1,col+1);
 	for(i=0;i<k;i++)
 	{
 	 return_val=return_val + a[row][i]*b[i][col];
 	 printf("\n\n Thread %d-%d calculated!",row+1,col+1);
 	 z=rand()%10;
 	 printf("\n\nThread %d-%d going for sleep",row+1,col+1);
 	 sleep(z);
 	 printf("\n\nThread %d-%d resumed...",row+1,col+1);
 	 //count++;
 	}
 	//return ((void *) return_val);
	printf("\n...........Thread No %d-%d .......exits", row+1,col+1);
	pthread_exit((void *) return_val);	
     
} 
void accept(int a[MAX][MAX],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\nEnter [%d][%d] :",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	 	
	}
}
void display(int a[MAX][MAX],int r,int c)
{
	int k,l;
	for(k=0;k<r;k++)
	{
		for(l=0;l<c;l++)
		{
			printf("%d\t",a[k][l]);
			
		}
		printf("\n");
	 	
	}
}
void main()
{
	int i,r1,c1,r2,c2,j,k ,*status;
	int rcArg[3];
	// declaring three threads 
    pthread_t th[MAX_TH][MAX_TH];
	
	printf("\nEnter rows and column for matrix 1 :");
	scanf("%d%d",&r1,&c1);
	printf("\nEnter rows and column for matrix 2 :");
	scanf("%d%d",&r2,&c2);

	while(c1!=r2)
	{
		printf("\nRe-enter values ------------");
		printf("\nr1,c1 :");
		scanf("%d%d",&r1,&c1);
		printf("\nr2,c2 :");
		scanf("%d%d",&r2,&c2);

	}
	printf("\nEnter values for matrix 1 :");
	accept(a,r1,c1);
	printf("\nEnter values for matrix 2 :");
	accept(b,r2,c2);
	
	printf("\nMatrix 1 :\n");
	display(a,r1,c1);
	printf("\nMatrix 2 :\n");
	display(b,r2,c2);
	
	 
  
    // Creating three threads, each evaluating its own part 
    for ( i= 0; i < r1; i++) 
    {  
    	for(j=0;j< c2 ;j++)
    	{
    		 rcArg[0]=i;
    		 rcArg[1]=j;
    		 rcArg[2]=c2;
    	     if(pthread_create(&th[i][j], NULL, multi,rcArg)!=0)
    	     	printf("\nThread not created !");
    	     else
    	     {
    	     	printf("\n\nThread %d-%d created!",i+1,j+1);
    	     	sleep(2);
    	     }	 
    	}
    } 
    
    // joining and waiting for all threads to complete 
    for (i = 0; i < r1; i++)  
    {
    	for(j=0; j< c2;j++)
    	{
    		if(pthread_join(th[i][j], (void **) &status)!=0)
    			printf("\n\nFailed to join thread %d-%d",i+1,j+1);
    		else
    		{
    			printf("\n\nThread %d-%d joined!",i+1,j+1);
    			c[i][j]=(long int)status; 
    		}
    	}
    }
        
    
    printf("\nResultant Matrix  :\n");    
    //displaying matrix
    display(c,r1,c1);
	
	
	
	
}
