#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define buf_size 10000
int main(){
    char buf[buf_size];
    printf("$ ./myFemtoShell\n");
    while(1){
        printf("Femto shell > ");
        if(fgets(buf,buf_size,stdin) != 0){
            if(strcmp(buf,"exit\n")==0){
                printf("Good bye\n");
                break;
            }
            else if(strncmp(buf,"echo ",5)==0){
                printf("%s",buf+5);
            }
            else if(strcmp(buf,"\n")==0){

            }
            else{
                printf("invalid command\n");
            }
        }
        else{
            printf("error while reading\n");
        }
    }
    return 0;
}
