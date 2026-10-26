#include <stdio.h>
#include <string.h>
// Write a code to sort strings (insertion sort algorithm) in descending order and
// find the longest string after sorting.

int main()
{
    char arr[10][20], key[20];
    int n, i, j, longest = 0;

    printf("Enter no. of strings: ");
    scanf("%d", &n);

    printf("Enter strings:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    for (i = 1; i < n; i++)
    {
        strcpy(key, arr[i]);
        j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) < 0)
        {
            strcpy(arr[j + 1], arr[j]);
            j--;
        }
        strcpy(arr[j + 1], key);
    }

    printf("Sorted array of strings (descending): ");
    for (i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
        if (strlen(arr[i]) > longest)
        {
            longest = strlen(arr[i]);
        }
    }
    printf("\nLongest string length: %d\n", longest);
    printf("Longest string is: %s", arr[0]);
    return 0;
}