#include <stdio.h>

int maxArray[100][100];
int allocation[100][100];
int need[100][100];
int available[100][100];
int n, m;

void input()
{
    int i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of instances: ");
    scanf("%d", &m);
    printf("Enter the allocation matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter the maximum matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &maxArray[i][j]);
        }
    }
    printf("Enter the available matrix:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &available[0][i]);
    }
}

void cal()
{
    int finish[100], temp, need[100][100], flag = 1, k, count = 0;
    int dead[100];
    int safe[100];
    int i, j;
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
        dead[i] = 0;
        safe[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = maxArray[i][j] - allocation[i][j];
        }
    }
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            int c = 0;
            for (j = 0; j < m; j++)
            {
                if (finish[i] == 0 && need[i][j] <= available[0][j])
                {
                    c++;
                    if (c == m)
                    {
                        for (k = 0; k < m; k++)
                        {
                            available[0][k] = available[0][k] + allocation[i][k];
                            finish[i] = 1;
                            flag = 1;
                        }
                        if (finish[i] == 1)
                        {
                            i = n;
                        }
                    }
                }
            }
        }
    }
    j = 0;
    flag = 0;
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            dead[j] = i;
            j++;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("\nDeadlock Ahead\n");
        printf("The processes that are deadlocked are: ");
        for (i = 0; i < j; i++)
        {
            printf("%d ", dead[i]);
        }
    }
    else
    {
        printf("\nSafe Ahead\n");
    }
}
int main()
{
    int i, j;
    input();
    cal();
    return 0;
}
