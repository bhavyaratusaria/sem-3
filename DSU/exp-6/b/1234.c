#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k, min, cmp_count = 0;
    char temp[20];
    char arr[5][20] = {"banana", "apple", "orange", "grape", "mango"};

    for (i = 0; i < 4; i++)
    {
        min = i;
        for (j = i + 1; j < 5; j++)
        {
            cmp_count++;
            k = 0;
            while (arr[j][k] != '\0' && arr[j][k] == arr[min][k])
            {
                k++;
            }
            if (arr[j][k] > arr[min][k])
            {
                min = j;
            }
        }
        if (min != i)
        {
            strcpy(temp, arr[min]);
            strcpy(arr[min], arr[i]);
            strcpy(arr[i], temp);
        }
    }

    printf("Sorted Array: ");
    for (i = 0; i < 5; i++)
    {
        printf("%s ", arr[i]);
    }

    char longest[20];
    strcpy(longest, arr[0]);
    for (i = 1; i < 5; i++)
    {
        if (strlen(arr[i]) > strlen(longest))
        {
            strcpy(longest, arr[i]);
        }
    }

    printf("\nLongest String: %s", longest);
    printf("\nTotal Comparisons: %d\n", cmp_count);

    return 0;
}
