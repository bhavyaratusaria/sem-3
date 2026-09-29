#include <stdio.h>

int main()
{
    int n, qt, i, j, time = 0, ct[10], at[10], bt[10], rem[10], wt[10], tat[10], pid[10], temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    printf("Enter quantum time slice: ");
    scanf("%d", &qt);

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter AT and BT for P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rem[i] = bt[i];
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

                temp = rem[i];
                rem[i] = rem[j];
                rem[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    j = 0;
    while (j != 1)
    {
        j = 1;
        for (i = 0; i < n; i++)
        {
            if (rem[i] > 0)
            {
                j = 0;
                if (time < at[i])
                {
                    time = at[i];
                }
                if (rem[i] > qt)
                {
                    time += qt;
                    rem[i] -= qt;
                }
                else
                {
                    time += rem[i];
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    rem[i] = 0;
                    wt[i] = tat[i] - bt[i];

                    avg_wt += wt[i];
                    avg_tat += tat[i];
                }
            }
        }
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f\n", avg_wt / n);
    printf("Average TAT = %.2f\n", avg_tat / n);
    return 0;
}
