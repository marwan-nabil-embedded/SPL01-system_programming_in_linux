#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define COUNT 100
int main(int argc,char **argv){
	char buf[COUNT];
	if (argc !=2){
	        printf("Usage: %s file-name\n",argv[0]);
      	 	exit(-1);	       
	}
	int fd = open(argv[1],O_RDONLY);
	if(fd < 0){
		printf("could not open the file \n");
		exit(-2);
	}
	int num_read;
	while((num_read = read(fd, buf ,COUNT)) > 0){
		if(write(1,buf,num_read)<0){
			printf("Write failed\n");
			exit(-3);
		}
	}
	return 0;
}
