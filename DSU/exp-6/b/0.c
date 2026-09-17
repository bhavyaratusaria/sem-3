#include <stdio.h>
#include <string.h>
// Write a 'C' Program to Sort an Array of Strings using Selection Sort Method

int main()
{
    int i, j, min;
    char temp[20];
    char arr[5][20] = {"banana", "apple", "orange", "grape", "mango"};

    for (i = 0; i < 4; i++)
    {
        min = i;
        for (j = i + 1; j < 5; j++)
        {
            if (strcmp(arr[j], arr[min]) < 0)
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
    return 0;
}