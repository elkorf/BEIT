

#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#define size 5
int arr[size];
int in,out,res;

void *prod_function(void *arg);
void *cons_function(void *arg);

sem_t empty,full;
pthread_mutex_t MUTEX;

void init()
{
	res=sem_init(&full,0,0);
	if(res!=0)
		printf("\nError in initializing full!!!");

	res=sem_init(&empty,0,size);
	if(res!=0)
		printf("\nError in initializing empty!!!");

	res = pthread_mutex_init(&MUTEX, NULL);
	if(res!=0)
	{
		printf("\nError in initialing mutex variable!!!\n");
		exit(0);
	}
}
void main()
{
 	int i;
	in=0,out=0;
	int prod,cons;

	pthread_t  p_thread,c_thread;

	void *thread_result;
	
	printf("\nEnter number of producer :");
	scanf("%d",&prod);
	
	printf("\nEnter number of consumer :");
	scanf("%d",&cons);
	
	printf("\nInitializing...");
		//INITIALIZING BUFFER
	for(i=0;i<size;i++)
		arr[i] = 0;
		
		//PRINTING INITIAL BUFFER	
	printf("\n\n\n ::::: BUFFER [");
	for(i=0;i<size;i++)
		fprintf(stderr," %d ,",arr[i]);
	printf("]::::\n\n\n");
	

	p_thread=(pthread_t*) malloc(prod*sizeof(pthread_t));
	c_thread=(pthread_t*) malloc(cons*sizeof(pthread_t));

	init();

	printf("\nCreating producers");
	for(i=0;i<prod;i++)
	{
		res=pthread_create(&p_thread,NULL,prod_function,i);
		if(res!=0)
		{	
			printf("\nError in creating %dth thread!!",i+1);
			exit(EXIT_FAILURE);
		}
	}

	printf("\nCreating consumers");
	for(i=0;i<cons;i++)
	{
		res=pthread_create(&c_thread,NULL,cons_function,i);
		if(res!=0)
		{	
			printf("\nError in creating %dth thread!!",i+1);
			exit(EXIT_FAILURE);
		}
	}

	sleep(20);

	printf("\n\nWaiting for producer thread to finish...");
	for(i=0;i<prod;i++)
	{	
		res = pthread_join(p_thread, NULL);
		if (res != 0) 
		{
			perror("Thread join failed");
			exit(EXIT_FAILURE);
		}
		
		printf("\n\nProducer thread joined.... ");
	}	
	
	printf("\n\nWaiting for consumer thread to finish...");
	for(i=0;i<cons;i++)
	{	
		res = pthread_join(c_thread, NULL);
		if (res != 0) 
		{
			perror("Thread join failed");
			exit(EXIT_FAILURE);
		}
		printf("\n\nConsumer thread joined...");
	}
	exit(EXIT_SUCCESS);
}

void *prod_function(void *arg)
{
	int num,i;
	int p=(int *)arg;

	while(1)
	{
		
		num=rand()%10;
		sleep(num);
		sem_wait(&empty);
		pthread_mutex_lock(&MUTEX); 
		
		//critical section
		arr[in]=num;
		in=(in+1)%size;
		
		printf("\n%d producer added %d to buffer",p+1,num);
		printf("\n BUFFER :: [ ");
		for(i=0;i<size;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("] ");
		pthread_mutex_unlock(&MUTEX);
		sem_post(&full);
		
	}

	pthread_exit("\nSuccessfully executed!");
	
}

void *cons_function(void *arg)
{
	int num,i;
	int p=(int *)arg;

	while(1)
	{
		
		sem_wait(&full);
		pthread_mutex_lock(&MUTEX); 
		
		//critical section
		num=arr[out];
		arr[out]=0;
		out=(out+1)%size;
		printf("\n%d consumer consumed %d from buffer",p+1,num);
		printf("\n BUFFER :: [ ");
		for(i=0;i<size;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("] ");
		pthread_mutex_unlock(&MUTEX);
		sem_post(&empty);
		//sleep(5);
	}

	pthread_exit("\nSuccessfully executed!");
	
}
