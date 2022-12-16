#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#define MaxCrops 5 // Maximum crops a Farmer can produce or a Shpoowner can take
#define warehouseSize 5 // Size of the warehouse
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'}; //indicating room for different crops
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'}; //initially all the room is empty
pthread_mutex_t mutex;


void *Farmer(void *far)
{
    int i;
    int id = (*(int *)far);
    for (i = 0; i < MaxCrops; i++)
    {
        // critical_section
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        warehouse[in] = crops[id];
        printf("Farmer %d insert crops %c at %d\n", id, crops[id], in);
        in = (in + 1) % warehouseSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    printf("farmer %d: ", *(int*)far);
    for (int i = 0; i < warehouseSize; i++){
        printf("%c", warehouse[i]);
    }
    printf("\n");
}


void *ShopOwner(void *sho)
{
    int i;
    int id = *(int *)sho;
    for (i = 0; i < MaxCrops; i++)
    {
        // critical_section
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        warehouse[out] = 'N';
        printf("ShopOwner %d remove crops %c from %d\n", id, warehouse[out], out);
        out = (out + 1) % warehouseSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    
    printf("Shop Owner %d: ", *(int*)sho);
    for (int i = 0; i < warehouseSize; i++){
        printf("%c", warehouse[i]);
    }
    printf("\n");
}

int main()
{
    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize);
    sem_init(&full, 0, 0);
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
    
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
