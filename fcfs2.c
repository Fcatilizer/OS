//FCFS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

void sort(struct process *p, int n)
{
    int i, j;
    struct process temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - i - 1); j++)
        {
            if (p[j].arrival_time > p[j + 1].arrival_time)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void find_completion_time(struct process *p, int n)
{
    int i;
    p[0].completion_time = p[0].arrival_time + p[0].burst_time;
    for (i = 1; i < n; i++)
    {
        if (p[i].arrival_time > p[i - 1].completion_time)
        {
            p[i].completion_time = p[i].arrival_time + p[i].burst_time;
        }
        else
        {
            p[i].completion_time = p[i - 1].completion_time + p[i].burst_time;
        }
    }
}

void find_turn_around_time(struct process *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
    }
}

void find_waiting_time(struct process *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
    }
}

void find_avg_time(struct process *p, int n)
{
    int i, total_waiting_time = 0, total_turn_around_time = 0;
    for (i = 0; i < n; i++)
    {
        total_waiting_time += p[i].waiting_time;
        total_turn_around_time += p[i].turn_around_time;
    }
    printf("Average waiting time = %f\n", (float)total_waiting_time / (float)n);
    printf("Average turn around time = %f\n", (float)total_turn_around_time / (float)n);
}

void display(struct process *p, int n)
{
    int i;
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turn_around_time, p[i].waiting_time);
    }
}

int main()
{
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i + 1;
    }
    sort(p, n);
    find_completion_time(p, n);
    find_turn_around_time(p, n);
    find_waiting_time(p, n);
    find_avg_time(p, n);
    display(p, n);
    return 0;
}

// Language: c