#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
// #include<sys/wait.h>

int thread_count = 1;
void threadfunctions()
{
    sleep(1);
    printf("\n Thread Running %d\n", thread_count);
    Return NULL;
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, threadfunctions, NULL);
        pthread_join(thread_id, NULL);
        printf("\n Thread Closed %d\n", thread_count);
        thread_count++;
        exit(0);
        return 0;
    }
}