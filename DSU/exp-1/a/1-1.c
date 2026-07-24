#include <stdio.h>

// WAP to find largest and smallest element in an array

int main()
{
    int arr[5], i, l, s;

    printf("Enter 5 nos.: ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    l = arr[0];
    s = arr[0];

    for (i = 1; i < 5; i++)
    {
        if (arr[i] > l)
        {
            l = arr[i];
        }
    }

    for (i = 1; i < 5; i++)
    {
        if (arr[i] < s)
        {
            s = arr[i];
        }
    }

    printf("Largest: %d\n", l);
    printf("Smallest: %d", s);
    return 0;
}