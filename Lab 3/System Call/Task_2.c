#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
    int a;
    a = fork();
    if (a==0){
        int b;
        b = fork();
        if (b==0){
            printf("I am grandchild\n");
        }
        else{
            wait(NULL);
            printf("I am child\n");
        }
    }
    else{
        wait(NULL);
        printf("I am parent\n");
    }
}
