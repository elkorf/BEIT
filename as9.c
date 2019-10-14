#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

	int ch=2,fp;
	char buf[20];
	
	fp = open("file.txt",O_RDWR | O_CREAT);
	
	if(fp==-1){
		printf("An error occured");
		return 0;
	}
	
	while(ch!=6){
		printf("\tMENU\n1.Insert Record\n2.Display all\n3.Search record\n4.Modify Record\n5.Delete Record\n6.Exit: ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1://ins
				
				break;
			case 2: //disp
				printf("Contents of file are: \n");
				read(fp,buf,sizeof(buf));
				
				for(int i=0;i<sizeof(buf);i++)
					printf("%c",buf[i]);
					
				break;
			case 3: //search
				break;
			case 4: //mod
				break; 
			case 5:	//del
				break;
			case 6:	//exit
				printf("Bye!");
				exit(0);
				break;
			default:
				printf("Invalid Choice Try again!");		
		}
	}
}
