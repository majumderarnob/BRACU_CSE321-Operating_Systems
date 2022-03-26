#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    int p_id, c_pid, g_pid;
    int count = 0;
    p_id = fork();
    if (p_id == 0)
    {
        c_pid = getpid();
        p_id = fork();
        if (p_id == 0)
        {
            g_pid = getpid();
            printf("Child process id: %d\n", c_pid);
            printf("Grandchild process id: %d\n", g_pid);
        }
        else
        {
            printf("Child process id: %d\n", c_pid);
        }
    }
    else if (p_id == -1)
    {
        printf("Fork failed\n");
    }
    else
    {
        printf("Parent process id: %d\n", p_id);
    }
}
