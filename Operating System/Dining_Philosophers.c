#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
  
#define N 5 
#define THINKING 2 
#define HUNGRY 1 
#define EATING 0 
#define LEFT (num + 4) % N 
#define RIGHT (num + 1) % N 
  
int state[N]; 
int phil[N] = { 0, 1, 2, 3, 4 }; 
  
sem_t mutex; 
sem_t S[N]; 
void take_chop(int num);
void put_chop(int num);
void test(int num)
{
	if(state[num]== HUNGRY && state[LEFT]!=EATING && state[RIGHT]!=EATING)
	{
		state[num]=EATING;
		sleep(2);

		printf("Philosopher %d takes fork %d and %d\n",num+1,LEFT+1,num+1);

		printf("  Philospher %d is eating..!\n",num+1);

		sem_post(&S[num]);
		
	}
}

void take_chop(int num)
{
	sem_wait(&mutex);

	state[num]=HUNGRY;

	printf("\t\tPhilosopher %d is hungry..!\n",num+1);

	test(num);

	sem_post(&mutex);

	sem_wait(&S[num]);

	sleep(1);
}

void put_chop(int num)
{
	sem_wait(&mutex);

	state[num]=THINKING;

	printf("\tPhilosopher %d is thinking..!\n",num+1);

	printf("Philosopher %d putting fork %d and %d\n",num+1,LEFT+1,num+1);

	test(LEFT);
	test(RIGHT);

	sem_post(&mutex);
}

void* philosopher(void* num)
{
	while(1)
	{
		int *i=num;
		sleep(2);
		take_chop(*i);
		sleep(1);
		put_chop(*i);
	}
}


void main()
{
	int i;
	pthread_t th[N];

	sem_init(&mutex,0,1);

	for(i=0;i<N;i++)
	{
		sem_init(&S[i],0,0);
	}

	for(i=0;i<N;i++)
	{
		pthread_create(&th[i],NULL,philosopher,&phil[i]);
	}

	for(i=0;i<N;i++)
		pthread_join(th[i],NULL);
}
