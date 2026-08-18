#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int at[20], bt[20], ct[20], wt[20], tat[20], p[20];
    float avgwt = 0, avgtat = 0;

    printf("Enter no. of Processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    if (at[0] > 0)
    {
        ct[0] = at[0] + bt[0];
    }
    else
    {
        ct[0] = bt[0];
    }

    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    for (i = 1; i < n; i++)
    {
        if (ct[i - 1] < at[i])
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("Average Waiting Time = %.2f\n", avgwt / n);
    printf("Average Turnaround Time = %.2f", avgtat / n);
    return 0;
}