#include <stdio.h>
struct process
{
    int waiting_time, arrival_time, brust_time, turn_arround_time;
};

struct process a[10];

int main()
{
    int n, temp[10];
    int count = 0, t = 0, p;
    float total_waiting_time = 0, total_turn_arround_time = 0, average_waiting_time, average_turn_arround_time;
    printf("Enter the number of the process\n");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time of the process\n");
    printf("arrival_time   waiting_time\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i].arrival_time, &a[i].brust_time);
        temp[i] = a[i].brust_time;
    }
    a[9].brust_time = 10000;
    for (t = 0; count != n; t++)
    {
        p = 9;
        for (int i = 0; i < n; i++)
        {
            if (a[i].brust_time < a[p].brust_time && (a[i].arrival_time <= t && a[i].brust_time > 0))
            {
                p = i;
            }
        }
        a[p].brust_time = a[p].brust_time - 1;
        if (a[p].brust_time == 0)
        {
            count++;
            a[p].waiting_time = t + 1 - a[p].arrival_time - temp[p];
            a[p].turn_arround_time = t + 1 - a[p].arrival_time;
            total_waiting_time = total_waiting_time + a[p].waiting_time;
            total_turn_arround_time = total_turn_arround_time + a[p].turn_arround_time;
        }
    }
    average_waiting_time = total_waiting_time / n;
    average_turn_arround_time = total_turn_arround_time / n;
    printf("waiting_time    turn_arround_time\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t%d\n", i + 1, a[i].waiting_time, a[i].turn_arround_time);
    }
    printf("Avg waiting time of the process is %f\n", average_waiting_time);
    printf("Avg turn around time of the process %f\n", average_turn_arround_time);
}
