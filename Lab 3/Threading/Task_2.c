#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int glob_var = 1;
void *threadFunction(void *argv)
{
    int *thread = (int *)argv;
    for (int i = 0; i < 5; ++i)
    {
        printf("Thread %d prints %d\n", *thread, glob_var);
        glob_var++;
    }
    return NULL;
}
int main()
{
    pthread_t thread_id1, thread_id2, thread_id3, thread_id4, thread_id5;
    int thread_num1 = 1, thread_num2 = 2, thread_num3 = 3, thread_num4 = 4, thread_num5 = 5;

    pthread_create(&thread_id1, NULL, threadFunction, (void *)&thread_num1);
    pthread_create(&thread_id2, NULL, threadFunction, (void *)&thread_num2);
    pthread_create(&thread_id3, NULL, threadFunction, (void *)&thread_num3);
    pthread_create(&thread_id4, NULL, threadFunction, (void *)&thread_num4);
    pthread_create(&thread_id5, NULL, threadFunction, (void *)&thread_num5);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);
    pthread_join(thread_id4, NULL);
    pthread_join(thread_id5, NULL);
    exit(0);
}