#include <stdio.h>
struct process
{
    int waiting_time, arrival_time, Burst_time, Turn_arround_time, priority;
};

struct process a[10];

int main()
{
    int n, temp[10], t, count = 0, p;
    float total_WT = 0, total_TAT = 0, Avg_WT, Avg_TAT;
    printf("Enter the number of the process\n");
    scanf("%d", &n);
    printf("Enter the arrival time , burst time and priority of the process\n");
    printf("arrival_time  Burst_time  priority\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &a[i].arrival_time, &a[i].Burst_time, &a[i].priority);

        temp[i] = a[i].Burst_time;
    }
    a[9].priority = 10000;

    for (t = 0; count != n; t++)
    {
        p = 9;
        for (int i = 0; i < n; i++)
        {
            if (a[p].priority > a[i].priority && a[i].arrival_time <= t && a[i].Burst_time > 0)
            {
                p = i;
            }
        }

        a[p].Burst_time = a[p].Burst_time - 1;
        if (a[p].Burst_time == 0)
        {
            count++;
            a[p].waiting_time = t + 1 - a[p].arrival_time - temp[p];
            a[p].Turn_arround_time = t + 1 - a[p].arrival_time;

            total_WT = total_WT + a[p].waiting_time;
            total_TAT = total_TAT + a[p].Turn_arround_time;
        }
    }

    Avg_WT = total_WT / n;
    Avg_TAT = total_TAT / n;

    printf("waiting_time Turn_arround_time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\n", i + 1, a[i].waiting_time, a[i].Turn_arround_time);
    }

    printf("Avg waiting time of the process  is %f\n", Avg_WT);
    printf("Avg turn around time of the process is %f\n", Avg_TAT);

    return 0;
}