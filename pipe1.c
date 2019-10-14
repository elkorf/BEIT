//IPC using unnamed pipe
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	char ar[10]="hi there",op[10];
	pid_t pid;
	int fd[2];
	
	pipe(fd);
	
	pid = fork();
	
	if(pid < 0)
	{
		printf("\nError in fork!");
		return 0;
	}
	if(pid == 0)
	{
		printf("\nIn child!");
		read(fd[0],op,10);
		printf("\nData read is: %s",op);
		
	}else{
		printf("\nIN parent!");
		
		if(!write(fd[1],ar,10))
		{
			printf("\nPipe creation failed!");
			return 0;			
		}
		
		printf("\nDATA IS WRITTEN TO PIPE");
		
	}


	return 0;
}
