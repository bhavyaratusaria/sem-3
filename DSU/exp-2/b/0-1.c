#include <stdio.h>
// Write a 'C' Program to Find Maximum AND Value
// Produced by Pairwise Elements of an Array

int main()
{
    int arr[100], n, i, j, max_and = 0;

    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            int and_value = arr[i] & arr[j];
            if (and_value > max_and)
            {
                max_and = and_value;
            }
        }
    }

    printf("Maximum AND value: %d\n", max_and);
    return 0;
}