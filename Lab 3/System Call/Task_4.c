#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ll long long 
#define LENGTH 1000 


int main(int argc, char *argv[]){
    pid_t a = fork();
    if (a==0){
        argv[0] = "./sort";
        execv(argv[0], argv);
    }
    else{
        wait(NULL);
        argv[0] = "./oddeven";
        execv(argv[0], argv);
    }
}
