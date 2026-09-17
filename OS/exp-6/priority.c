#include <stdio.h>
// priority scheduling program in c (beginner friendly)

int main()
{
    int i, j, n, bt[10], p[10], wt[10], tat[10], temp, pid[10];
    float total_wt = 0, total_tat = 0;

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter BT and priority P%d: ", i + 1);
        scanf("%d %d", &bt[i], &p[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

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
    total_wt = 0;

    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nPID\tBT\tP\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("p%d\t%d\t%d\t%d\t%d\n", pid[i], bt[i], p[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f\n", total_wt / n);
    printf("Average TAT = %.2f\n", total_tat / n);
    return 0;
}