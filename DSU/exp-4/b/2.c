#include <stdio.h>
#include <string.h>
//  Implement recursive Binary Search for strings.

int sort(char arr[][20], int n)
{
    int i, j;
    char temp[20];
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    printf("Sorted array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
    }
    return 0;
}
int binarySearch(char arr[][20], int low, int high, char key[])
{
    int mid = (low + high) / 2;

    if (strcmp(arr[mid], key) == 0)
    {
        return mid;
    }
    else if (strcmp(arr[mid], key) > 0)
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

    printf("Enter string: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }
    sort(arr, n);

    printf("\nEnter string to find: ");
    scanf("%s", key);

    low = 0;
    high = n - 1;
    mid = binarySearch(arr, low, high, key);

    printf("Element found at position: %d", mid + 1);
    return 0;
}