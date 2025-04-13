#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#define COUNT 1000
int main(int argc,char **argv){
	int source,dest,n_read;
	char buf[COUNT];

	if(argc != 3){
		write(STDERR_FILENO,"Usage: cp <source_file> <destination_file>\n",44);
		exit(1);
	}
	source = open(argv[1],O_RDONLY);//read only 
	if(source < 0){
		perror("error opening file");
		exit(1);
	}
	//open or create the destination file 
	dest = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0644);
	if(dest < 0){
		perror("error open or create destination file ");
		close(source);
		exit(1);
	}
	//read from source and write to destination 
	while((n_read= read(source,buf,COUNT))>0){
		if(write(dest,buf,n_read)!= n_read){
			perror("error writeing in destination");
			close(source);
			close(dest);
			exit(1);
		}
	}
	if (n_read < 0){
		perror("error reading source");
	}
	close(source);
	close(dest);
	return 0;
}
