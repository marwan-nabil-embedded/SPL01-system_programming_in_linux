#include<stdio.h>
#include<stdlib.h>


int main(int argc , char **argv){
	//check correct number of arguments
	if(argc != 3){
		printf("Usage : mv  <source_file> <destination_file>\n");
		exit(1);
	}
	//call rename() to move or rename the file
	if(rename(argv[1],argv[2]) != 0){
		printf("error\n");
		exit(1);
	}
	return 0;
}
