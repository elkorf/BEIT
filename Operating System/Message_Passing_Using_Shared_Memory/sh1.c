 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
 

int main() 
{ 
	// ftok to generate unique key 
	key_t key = ftok(".",'aaa'); 

	printf("Key :%d",key);
	// shmget returns an identifier in shmid 
	int shmid = shmget(key,1024,0666|IPC_CREAT); 
	//int shmid = shmget((key_t)100,1024,0666|IPC_CREAT); 

	// shmat to attach to shared memory 
	char *str = (char*) shmat(shmid,(void*)0,0); 
	printf("\nMemory address :%X",(int)str);
	
	printf("\nWrite Data : "); 
	gets(str); 
	printf("\nData written in memory: %s",str); 
	
	//detach from shared memory 
	shmdt(str);

	//shmctl(shmid,IPC_RMID,NULL); 
	
	while(1);
	return 0; 
} 

