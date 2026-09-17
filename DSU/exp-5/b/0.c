#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    char temp[20], arr[5][20] = {"Orange", "Apple", "Banana", "Grapes", "Mango"};

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4 - i; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }

    printf("Sorted Array: ");
    for (i = 0; i < 5; i++)
    {
        printf("%s ", arr[i]);
    }
    return 0;
}
