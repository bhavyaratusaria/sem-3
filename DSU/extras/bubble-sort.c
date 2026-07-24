#include <stdio.h>
#include <stdlib.h>
// bubble sort
int main()
{
    int i, j, n, temp;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int *ptr = (int *)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }

    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }
    free(ptr);
    return 0;
}