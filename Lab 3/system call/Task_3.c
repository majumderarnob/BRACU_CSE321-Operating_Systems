#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void forkexample()
{
    int x = 1;
    if (fork() == 0)
    {
        printf("Chilf has x = %d\n", ++x);
    }
    else
    {
        printf("Parent has x = %d\n", --x);
    }
    return 0;
}