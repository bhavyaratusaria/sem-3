#include <stdio.h>

int main()
{
    int i, j, n, pid[10], bt[10], tat[10], wt[10], temp;
    int total_wt = 0, total_tat = 0;

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter Burst Time for p%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    total_tat = tat[0];

    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];

        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }

    printf("\nPID\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("p%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %d\n", total_wt / n);
    printf("Average Turnaround Time = %d\n", total_tat / n);

    return 0;
}
