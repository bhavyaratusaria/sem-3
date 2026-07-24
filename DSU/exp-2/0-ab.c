#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// wap to linear search an element in an array, create functions for linear search and find element in an array and also find string in an array of strings. Make it menu driven program.
int search(int arr[], int n, int flag)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == flag)
        {
            return i;
        }
    }
    return -1;
}

int stringsearch(char str[][30], int n, char search[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(str[i], search) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, i, flag, choice;
    int *ptr;
    printf("Menu:\n1. Search in array of integers\n");
    printf("2. Search in array of strings\nEnter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        printf("Enter no. of elements: ");
        scanf("%d", &n);

        ptr = (int *)malloc(n * sizeof(int));
        printf("Enter elements: ");
        for (i = 0; i < n; i++)
        {
            scanf("%d", &ptr[i]);
        }

        printf("Enter no. to find: ");
        scanf("%d", &flag);

        int result = search(ptr, n, flag);
        if (result == -1)
        {
            printf("No. not found");
        }
        else
        {
            printf("No. found at position: %d\n", result + 1);
        }
        free(ptr);
        break;
    }
    case 2:
    {
        char str[10][30], search[30];

        printf("Enter strings: ");
        for (i = 0; i < 10; i++)
        {
            scanf("%s", str[i]);
        }

        printf("Enter string to find: ");
        scanf("%s", search);

        int stringResult = stringsearch(str, 10, search);

        if (stringResult == -1)
        {
            printf("String not found");
        }
        else
        {
            printf("String found at index: %d\n", stringResult + 1);
        }
        break;
    }
    default:
        printf("Enter 1 or 2");
    }
}