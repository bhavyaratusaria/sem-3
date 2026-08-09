#include <stdio.h>
// Find maximum OR value

int main()
{
    int arr[100], n, i, j, max_or = 0;

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
            int or_value = arr[i] | arr[j];
            if (or_value > max_or)
            {
                max_or = or_value;
            }
        }
    }

    printf("Maximum OR value: %d\n", max_or);
    return 0;
}