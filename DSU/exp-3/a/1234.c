#include <stdio.h>

int main()
{
    int arr[10], freq[100] = {0}, i, cmp = 0, max = 0;

    printf("Enter 10 elements for array: ");
    for (i = 0; i < 10; i++)
    {
        cmp += 2;
        scanf("%d", &arr[i]);
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cmp++;
    int small = arr[0];
    printf("Largest number = %d\n", max);

    for (i = 0; i < 10; i++)
    {
        freq[(unsigned int)arr[i]]++;
        cmp += 2;
        if (arr[i] < small)
        {
            small = arr[i];
        }
    }
    cmp++;

    printf("Smallest number = %d\n", small);

    printf("Occurrences:\n");
    for (i = 0; i <= max; i++)
    {
        cmp += 2;

        if (freq[i] > 0)
        {
            printf("'%d': %d\n", i, freq[i]);
        }
    }
    cmp++;
    printf("comparisons performed: %d", cmp);
    return 0;
}