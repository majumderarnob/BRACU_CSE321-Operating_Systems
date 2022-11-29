#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ll long long

void* runner(void *arg){
    printf("thread-%lld running\n", *(ll*)arg);
    pthread_exit(0);
}

int main(){
    for(ll i=0; i<5; i++){
        pthread_t tid;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        ll arg=i+1;
        pthread_create(&tid, &attr, runner, &arg);
        pthread_join(tid, NULL);
        printf("thread-%lld closed\n", i+1);    
    }
}