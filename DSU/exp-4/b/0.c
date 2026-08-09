#include <stdio.h>
#include <string.h>
// Write a 'C' Program to Search a Particular Data from the Given Array of Strings using Binary Search Method
// also it is in descending order array which is 1st part of exercise..
int main()
{
    char arr[10][20], key[20];
    int n, i, j, low, high, mid;
    char temp[20];
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter string:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i], arr[j]) < 0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    printf("Enter string to find: ");
    scanf("%s", key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (strcmp(arr[mid], key) == 0)
        {
            break;
        }
        else if (strcmp(arr[mid], key) > 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("Element found at position: %d", mid);
    return 0;
}