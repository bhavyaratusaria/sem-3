#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n, temp, min;
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
        min = i;
        for (j = i; j < n - 1; j++)
        {
            if (ptr[j + 1] < ptr[min])
            {
                min = j + 1;
            }
        }
        if (min != i)
        {
            temp = ptr[min];
            ptr[min] = ptr[i];
            ptr[i] = temp;
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