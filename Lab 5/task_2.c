#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define MaxCrops 5
#define warehouseSize 5

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'};
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'};
pthread_mutex_t mutex;

void *Farmer(void *far)
{
    int i;
    int id = (*(int *)far);
    for (i = 0; i < MaxCrops; i++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        warehouse[in] = crops[id];
        in = (in + 1) % warehouseSize;
        printf("Farmer %d insert crops %c at %d\n", id, crops[id], in);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *ShopOwner(void *sho)
{
    int i;
    int id = *(int *)sho;
    for (i = 0; i < MaxCrops; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        out = (out + 1) % warehouseSize;
        printf("ShopOwner %d remove crops %c from %d\n", id, warehouse[out], out);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{
    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize);
    sem_init(&full, 0, 0);
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {6, 7, 8, 9, 10};
    int i;
    for (i = 0; i < 5; i++)
    {
        pthread_create(&Far[i], NULL, Farmer, &a[i]);
        pthread_create(&Sho[i], NULL, ShopOwner, &b[i]);
    }
    for (i = 0; i < 5; i++)
    {
        pthread_join(Far[i], NULL);
        pthread_join(Sho[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}