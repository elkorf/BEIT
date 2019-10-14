#include <unistd.h>
//IPC using unnamed pipe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char path[10],readpath[10];
	pid_t pid;
	int fd[2],pip[2];
	char data[100],td[20],rd[100];
	
	pipe(fd);
	pipe(pip);
	
	memset(&data[0],0,sizeof(data));
	
	pid = fork();
	
	if(pid < 0)
	{
		printf("\nError in fork!");
		return 0;
	}
	if(pid == 0)
	{
		FILE *fp;
		close(fd[1]);
		read(fd[0],readpath,sizeof(readpath));
		close(fd[0]);
		
		printf("\nChild is reading file : %s",readpath);
		
		fp = fopen(readpath,"r");
		
		while(fscanf(fp,"%s",td)!=EOF)
		{
			strcat(data,td);
			strcat(data," ");		
		}
		
//		printf("\nData of file in parent is: %s",data);
		close(pip[0]);
		if(!write(pip[1],data,sizeof(data)))
		{
			printf("\nPipe 2 creation failed!");
			return 0;			
		}
		close(pip[1]);
	}else{
		printf("\nIN parent!\nEnter path of file to read: ");
		scanf("%s",path);
		
		close(fd[0]);
		if(!write(fd[1],path,sizeof(path)))
		{
			printf("\nPipe creation failed!");
			return 0;			
		}
		close(fd[1]);
	
		sleep(1);
	
		close(pip[1]);	
		read(pip[0],rd,sizeof(rd));
		close(pip[0]);		
	
		printf("\nData of file in parent is: %s\n",rd);
		
	}


	return 0;
}
