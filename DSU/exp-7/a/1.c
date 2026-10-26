#include <stdio.h>
// c code to implement insertion sort algorithm. Write a code to sort array in descending order.
// Count total shift, total comparisons performed.

int main()
{
    int arr[10], i, j, key, n, cmp = 0, shifts = 0;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
            shifts++;
        }
        arr[j + 1] = key;
    }
    printf("Sorted array (descending): ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nTotal comparisons: %d\n", cmp);
    printf("Total shifts: %d", shifts);
    return 0;
}