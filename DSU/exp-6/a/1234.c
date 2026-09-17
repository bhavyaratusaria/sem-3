#include <stdio.h>

int main()
{
    int i, j, temp, min;
    int arr[5] = {42, 17, 89, 5, 23};
    int cmp_count = 0, swap_count = 0;

    for (i = 0; i < 4; i++)
    {
        min = i;
        for (j = i; j < 4; j++)
        {
            cmp_count++;

            if (arr[j + 1] > arr[min])
            {
                min = j + 1;
            }
        }
        if (min != i)
        {
            swap_count++;
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    printf("Sorted Array: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nLargest Element: %d", arr[0]);
    printf("\nSmallest Element: %d", arr[4]);
    printf("\nTotal Comparisons: %d", cmp_count);
    printf("\nTotal Swaps: %d\n", swap_count);
    return 0;
}
