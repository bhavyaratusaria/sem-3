#include <stdio.h>
#include <string.h>
// Write a 'C' Program to Sort an Array of Strings using Insertion Sort Method

int main()
{
    char arr[10][20], key[20];
    int n, i, j;

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
        while (j >= 0 && strcmp(arr[j], key) > 0)
        {
            strcpy(arr[j + 1], arr[j]);
            j--;
        }
        strcpy(arr[j + 1], key);
    }

    printf("Sorted array of strings: ");
    for (i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
    }
    return 0;
}