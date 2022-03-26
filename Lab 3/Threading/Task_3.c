#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void asciiCount(void *input1)
{
    char *input = (char *)input1;
    int output = 0;
    int *result = malloc(sizeof(int));
    int i = 0;
    while (input[i] != '\0')
    {
        output += input[i];
        i++;
    }
    *result = output;
    return (void *)result;
}

int main()
{
    pthread_t id_1, id_2, id_3;
    char *name1 = "Alen";
    char *name2 = "Bert";
    char *name3 = "Cindy";
    printf("for user names: %s %s %s\n", name1, name2, name3);

    pthread_create(&id_1, NULL, asciiCount, name1);
    int *count;
    pthread_join(id_1, (void *)&count);

    pthread_create(&id_2, NULL, asciiCount, name2);
    int *count2;
    pthread_join(id_2, (void *)&count2);

    pthread_create(&id_3, NULL, asciiCount, name3);
    int *count3;
    pthread_join(id_3, (void *)&count3);

    if (*count == *count2 && *count == *count3)
    {
        printf("Youreka\n");
    }
    else if (*count == *count2 || *count == *count3 || *count2 == *count3)
    {
        printf("Miracle\n");
    }
    else
    {
        printf("Hasta La Vista\n");
    }
    return 0;
}