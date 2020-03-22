#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

#define N 10
int data=10;
sem_t mutex,wrt; 
int rcnt=0;
int rd,wt,res;
sem_t wrt, mutex;
void *reader(void *arg);
void *writer(void *arg);

void init()
{
	//data=10;
	res=sem_init(&wrt,0,1);
	if(res!=0)
		printf("Error in initialing writer!!!\n");

	res=sem_init(&mutex,0,1);
	if(res!=0)
	{
		printf("Error in initialing mutex variable!!!\n");
	}
}

void* writer(void *arg)
{
	int i;
	while(1)
	{
		sleep(1);
	
		int r=((int)arg);
		sem_wait(&wrt);
		printf("Writer %d is performing its task...\n",r+1);
		data--;
		printf("Writer %d updated %d data\n",r+1,data);
		sem_post(&wrt);
		//i++;
		sleep(1);
	}

}

void* reader(void *arg)
{
	while(1)
	{
		int r1=((int)arg);

		sem_wait(&mutex);
		rcnt=rcnt+1;
		if(rcnt==1)
			sem_wait(&wrt);

		sem_post(&mutex);

		printf("Reader %d is performing\n ",r1+1);
		printf("Reader %d reads %d data\n",r1+1,data);
		//printf("Reader %d finished!\n");
		sleep(1);
		sem_wait(&mutex);
		rcnt=rcnt-1;
		if(rcnt==0)
			sem_post(&wrt);
		sem_post(&mutex);
		sleep(1);
	}
}
void main()
{
	pthread_t  r_thread[N],w_thread[N];
	int i,j;

	
	
	printf("Enter number of reader :\n");
	scanf("%d",&rd);
	
	printf("Enter number of writer :\n");
	scanf("%d",&wt);
	

	

	init();

	printf("Creating readers and writers!!\n");
	for(i=0;i<rd;i++)
	{
		res=pthread_create(&r_thread[i],NULL,reader,(void *) i);
	}
	for(i=0;i<wt;i++)
	{
		res=pthread_create(&w_thread[i],NULL,writer,(void *) i);
	}

	for(i=0;i<wt;i++)
	{
		 pthread_join(w_thread[i], NULL);
	}

	for(i=0;i<rd;i++)
	{
		 pthread_join(r_thread[i], NULL);
	}
	printf("Writer and reader thread joined...!\n\n");
	//printf("Waiting for readers thread to finish...\n\n");
	/*for(i=0;i<rd;i++)
	{	
		
		if (res != 0) 
		{
			perror("Thread join failed\n\n");
			//exit(EXIT_FAILURE);
		}
		
		printf("Reader thread %d joined....!\n\n",i+1);
	}	
	*/
	
	//exit(EXIT_SUCCESS);
	
}

