#include <stdio.h>
#include <string.h>
//  Implement recursive Binary Search for strings.

int binarySearch(char arr[][20], int low, int high, char key[])
{
    int mid = (low + high) / 2;

    if (strcmp(arr[mid], key) == 0)
    {
        return mid;
    }

    if (strcmp(arr[mid], key) > 0)
    {
        return binarySearch(arr, low, mid - 1, key);
    }
    else
    {
        return binarySearch(arr, mid + 1, high, key);
    }
}

int main()
{
    char arr[10][20], key[20];
    int n, i, j, low, high, mid;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter string:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    printf("Enter string to find: ");
    scanf("%s", key);

    low = 0;
    high = n - 1;
    mid = binarySearch(arr, low, high, key);

    printf("Element found at position: %d", mid);
    return 0;
}