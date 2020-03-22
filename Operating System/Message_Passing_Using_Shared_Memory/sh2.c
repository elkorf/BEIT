 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h>  

int main() 
{ 
	// ftok to generate unique key 
	key_t key1 = ftok(".",'aaa'); 

	printf("Key :%d",key1);
	// shmget returns an identifier in shmid 
	int shmid = shmget(key1,1024,0666|IPC_CREAT); 
	//int shmid = shmget((key_t)100,1024,0666|IPC_CREAT); 


	// shmat to attach to shared memory 
	char *str = (char*) shmat(shmid,(void*)0,0); 
	
	printf("\nData read from memory: %s\n",str); 
	printf("\nMemory address :%X",(int)str);
	printf("%s",)
	//detach from shared memory 
	shmdt(str); 
	
	// destroy the shared memory 
	shmctl(shmid,IPC_RMID,NULL); 
	
	
	return 0; 
} 

