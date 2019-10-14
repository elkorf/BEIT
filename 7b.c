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
	
	
		memset(&ar[0],0,sizeof(ar));
		memset(&str[0],0,sizeof(str));
	
	
	//while(1){	
	
		printf("Enter a sentence: ");
		gets(ar);
		
		
		fifo1 = open("f1",O_WRONLY);
		write(fifo1, ar, strlen(ar));
		close(fifo1);
		
		
		
		fifo2 = open("f2",O_RDONLY);
		read(fifo2,ar,sizeof(ar));
		close(fifo2);
		
		printf("%s",ar);	
	//}
	return 0;
}
