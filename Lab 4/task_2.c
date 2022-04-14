#include <stdio.h>
#include <conio.h>

void main()
{
    int i, process_num, sum = 0, count = 0, y, time_quant, waiting_time = 0, turn_arround_time = 0, arrival_time[10], burst_time[10], flag[10];
    float avg_waiting_time, avg_tat;
    printf(" Total number of process: ");
    scanf("%d", &process_num);
    y = process_num;
    for (i = 0; i < process_num; i++)
    {
        printf("\n Enter the Arrival and Burst time[%d]\n", i + 1);
        printf(" Arrival time is: \t");
        scanf("%d", &arrival_time[i]);
        printf(" \nBurst time is: \t");
        scanf("%d", &burst_time[i]);
        flag[i] = burst_time[i];
    }

    printf("Enter the Time Quantum: \t");
    scanf("%d", &time_quant);
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (sum = 0, i = 0; y != 0;)
    {
        if (flag[i] <= time_quant && flag[i] > 0)
        {
            sum = sum + flag[i];
            flag[i] = 0;
            count = 1;
        }
        else if (flag[i] > 0)
        {
            flag[i] = flag[i] - time_quant;
            sum = sum + time_quant;
        }
        if (flag[i] == 0 && count == 1)
        {
            y--;
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, burst_time[i], sum - arrival_time[i], sum - arrival_time[i] - burst_time[i]);
            waiting_time = waiting_time + sum - arrival_time[i] - burst_time[i];
            turn_arround_time = turn_arround_time + sum - arrival_time[i];
            count = 0;
        }
        if (i == process_num - 1)
        {
            i = 0;
        }
        else if (arrival_time[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    avg_waiting_time = waiting_time * 1.0 / process_num;
    avg_tat = turn_arround_time * 1.0 / process_num;
    printf("\n Average Turn Around Time: \t%f", avg_waiting_time);
    printf("\n Average Waiting Time: \t%f", avg_tat);
    getch();
}