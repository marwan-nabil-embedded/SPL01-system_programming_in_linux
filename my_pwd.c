#include<stdio.h>
#include<unistd.h>
#define COUNT 1000
int main(){
        char buf[COUNT];
        if(getcwd(buf,COUNT) != NULL ){
                printf("%s\n",getcwd(buf,COUNT));
        }
        else{
                printf("can not reach it");
        }

return 0;
}
