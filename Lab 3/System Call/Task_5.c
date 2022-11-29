#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int x = 1;

int main(){
    int a = fork();
    if (a==0){
        x++;
        
        printf("%d. Child Process ID: %d\n", x, getpid());
        // printf("%d\n", getppid());
        int b = fork();
        x++;
        if (b==0){
            printf("%d. Grandchild Process ID:%d\n", x, getpid());
            // printf("%d\n", getppid()); 
        }
        int c = fork();
        x++; 
        if (b>0 && c==0){
            printf("%d. Grandchild Process ID:%d\n", x, getpid());
            // printf("%d\n", getppid()); 
        }
        int d= fork();
        x++;
        if (b>0 && c>0 && d==0){
            printf("%d. Grandchild Process ID:%d\n", x, getpid());
            // printf("%d\n", getppid()); 
        }
    }
    else{
        printf("%d. Parent Process ID: %d\n", x, getpid());
    }
}
