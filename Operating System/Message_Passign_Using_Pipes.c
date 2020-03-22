// C program to illustrate 
// pipe system call in C 
#include <stdio.h> 
#include <unistd.h> 
#define MSGSIZE 16 
char* msg1 = "hello, world #1"; 
char* msg2 = "hello, world #2"; 
char* msg3 = "hello, world #3"; 

int main() 
{ 
    int fd1[2];  // Used to store two ends of first pipe 
    int fd2[2];  // Used to store two ends of second pipe 
  
    char fixed_str[] = " Chikorde"; 
    char input_str[100]; 
    pid_t pid; 

	if (pipe(fd1) < 0) 
	{
		printf("pipe 1 failed!\n");
		exit(1);
	} 
	if (pipe(fd2) < 0) 
	{
		printf("pipe 2 failed!\n");
		exit(1);
	} 
	/* continued */
	/* write pipe */
	printf("Enter input string :");
	scanf("%s",input_str);
	pid=fork();
	if(pid<0)
	{
		printf("fork failed !\n");
		exit(1);
	}

	else if(pid>0)				//parent process
	{
		
		char concat_str[100]; 
		printf("========= Parent Process ==========\n");
	    	printf("parent process writes input string to fd1 and reads concanated string from fd2!\n");
		close(fd1[0]);  // Close reading end of first pipe 
	  
		// Write input string and close writing end of first pipe. 
		write(fd1[1], input_str, strlen(input_str)+1); 
		close(fd1[1]); 
	  
		// Wait for child to send a string 
		wait(NULL); 
	  	
		
		close(fd2[1]); // Close writing end of second pipe 
	  
		// Read string from child, print it and close 
		// reading end. 
		read(fd2[0], concat_str, 100); 
		printf("Concatenated string : %s\n", concat_str); 
		close(fd2[0]); 
	}
	else if(pid==0)				//child process
	{
		close(fd1[1]);  // Close writing end of first pipe 
		printf("========= Child Process ==========\n");
  		printf("Child process reads input string from fd1 and writes concanated string to fd2!\n");
		// Read a string using first pipe 
		char concat_str[100]; 
		read(fd1[0], concat_str, 100); 
	  
		// Concatenate a fixed string with it 
		int k = strlen(concat_str); 
		int i; 
		for (i=0; i<strlen(fixed_str); i++) 
		    concat_str[k++] = fixed_str[i]; 
	  
		concat_str[k] = '\0';   // string ends with '\0' 
	  
		// Close both reading ends 
		close(fd1[0]); 
		close(fd2[0]); 
	  
		// Write concatenated string and close writing end 
		write(fd2[1], concat_str, strlen(concat_str)+1); 
		close(fd2[1]); 
	  
		exit(0); 
	} 
	return 0; 
} 

