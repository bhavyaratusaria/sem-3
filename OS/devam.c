#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int bt[10], pr[10], wt[10], tat[10];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority for P%d: ", i + 1);
        scanf("%d %d", &bt[i], &pr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])
            {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, bt[i], pr[i], wt[i], tat[i]);

        avgwt = avgwt + wt[i];
        avgtat = avgtat + tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f", avgtat / n);
    return 0;
}