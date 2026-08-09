#include <stdio.h>

int main()
{
    int n, i, j;
    int at[20], bt[20], ct[20], wt[20], tat[20], p[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    // Input
    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;

        printf("\nProcess P%d\n", p[i]);

        printf("Arrival Time : ");
        scanf("%d", &at[i]);

        printf("Burst Time   : ");
        scanf("%d", &bt[i]);
    }

    // Sort according to Arrival Time
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                int temp;

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

    // Completion Time
    if (at[0] > 0)
        ct[0] = at[0] + bt[0];
    else
        ct[0] = bt[0];

    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    // Remaining Processes
    for (i = 1; i < n; i++)
    {
        if (ct[i - 1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\n------------------------------------------------------------");
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT");
    printf("\n------------------------------------------------------------");

    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               p[i], at[i], bt[i], ct[i], wt[i], tat[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\n------------------------------------------------------------");

    printf("\nAverage Waiting Time    = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);

    return 0;
}
