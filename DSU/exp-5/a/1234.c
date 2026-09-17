#include <stdio.h>
// bubble sort
// 1. Sort array in descending order.
// 2. Count total swaps performed.
// 3. Count total comparisons performed.
// 4. Find largest and smallest element after sorting.
// 5. Implement optimized Bubble Sort using flag variables.
int main()
{
    int i, j, n, temp;
    int swap = 0, cmp = 0; // Tracks metrics
    int f;                 // For optimization

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int *ptr = (int *)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    // Optimized Bubble Sort with Flag
    for (i = 0; i < n - 1; i++)
    {
        f = 0; // Reset flag for each pass
        for (j = 0; j < n - i - 1; j++)
        {
            cmp++; // Increment comparison counter

            // Changed to '<' for Descending order
            if (ptr[j] < ptr[j + 1])
            {
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;

                swap++; // Increment swap counter
                f = 1;  // Mark that a swap occurred
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (f == 0)
        {
            break;
        }
    }

    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Displaying requested metrics
    printf("Total comparisons: %d\n", cmp);
    printf("Total swaps: %d\n", swap);

    // Since array is sorted in descending order:
    // Index 0 is the Largest, Index n-1 is the Smallest
    if (n > 0)
    {
        printf("Largest element: %d\n", ptr[0]);
        printf("Smallest element: %d\n", ptr[n - 1]);
    }

    free(ptr);
    return 0;
}
