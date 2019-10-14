#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char ar[100],str[100];
	pid_t pid;
	int fifo1,fifo2,charcnt=0,spccnt=0,lincnt=1;
	
	mkfifo("f1",0777);
	mkfifo("f2",0777);
	
		
	//while(1){
	
		charcnt = spccnt = lincnt = 1;
		
		memset(&ar[0],0,sizeof(ar));
		memset(&str[0],0,sizeof(str));

	
		fifo1 = open("f1",O_RDONLY);
		read(fifo1,ar,sizeof(ar));
		close(fifo1);
		
		printf("\nData revieved is: %s\n",ar);
		
		for(int i=0;i<strlen(ar);i++)
		{
			if(ar[i]=='\n')
				lincnt++;
			else if(ar[i]==' ')
				spccnt++;
				
			charcnt++; 
		}
		
		sprintf(str,"\nCharacters: %d \nSpaces: %d \nLines: %d\n",charcnt,spccnt,lincnt);
		
		fifo2 = open("f2",O_WRONLY);
		write(fifo2, str, strlen(str));
		close(fifo2);
	//}
	return 0;
}
