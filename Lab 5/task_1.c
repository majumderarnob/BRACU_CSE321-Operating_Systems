#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define MAX 10
#define BUFLEN 6
#define NUMTHREAD 2

void *consumer(int *id);
void *producer(int *id);

char buffer[BUFLEN];
char source[BUFLEN];
int pCount = 0;
int cCount = 0;
int buflen;

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD] = {0, 1};
int i = 0;
int j = 0;

main()
{
    int i;
    pthread_t thread[NUMTHREAD];
    strcpy(source, "abcdef");
    buflen = strlen(source);
    for (i = 0; i < NUMTHREAD; i++)
    {
        pthread_create(&thread[i], NULL, producer, &thread_id[i]);
    }
    for (i = 0; i < NUMTHREAD; i++)
    {
        pthread_create(&thread[i], NULL, consumer, &thread_id[i]);
    }
    for (i = 0; i < NUMTHREAD; i++)
    {
        pthread_join(thread[i], NULL);
    }
    printf("\n");
}

void *producer(int *id)
{
    int i;
    pthread_mutex_lock(&count_mutex);
    while (pCount == MAX)
    {
        printf("Producer %d is waiting for empty buffer\n", *id);
        pthread_cond_wait(&nonEmpty, &count_mutex);
    }
    for (i = 0; i < BUFLEN; i++)
    {
        buffer[i] = source[i];
    }
    pCount++;
    printf("%d is produced %s in buffer\n", *id, source);
    pthread_cond_signal(&full);
    pthread_mutex_unlock(&count_mutex);
}

void *consumer(int *id)
{
    int i;
    pthread_mutex_lock(&count_mutex);
    while (cCount == MAX)
    {
        printf("Consumer %d is waiting for full buffer\n", *id);
        pthread_cond_wait(&full, &count_mutex);
    }
    for (i = 0; i < BUFLEN; i++)
    {
        buffer[i] = '\0';
    }
    cCount++;
    printf("%d is consuming %s from buffer\n", *id, buffer);
    pthread_cond_signal(&nonEmpty);
    pthread_mutex_unlock(&count_mutex);
}