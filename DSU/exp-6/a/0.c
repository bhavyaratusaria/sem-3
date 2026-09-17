#include <stdio.h>
// selection sort
int main()
{
    int i, j, temp, min;
    int arr[5] = {42, 17, 89, 5, 23};

    for (i = 0; i < 4; i++)
    {
        min = i;
        for (j = i; j < 4; j++)
        {
            if (arr[j + 1] < arr[min])
            {
                min = j + 1;
            }
        }
        if (min != i)
        {
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
    return 0;
}
