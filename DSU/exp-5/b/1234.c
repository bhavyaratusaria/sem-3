#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, cmp_count = 0;
    char temp[20], arr[5][20] = {"Orange", "Apple", "Banana", "Grapes", "Mango"};

    // 1 & 2: Bubble sort in descending order WITHOUT using strcmp()
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4 - i; j++)
        {
            cmp_count++; // 5. Track total comparisons

            int k = 0;
            // Loop until characters differ or a string ends
            while (arr[j][k] != '\0' && arr[j][k] == arr[j + 1][k])
            {
                k++;
            }

            // Check character values to sort descending (< 0 logic)
            if (arr[j][k] < arr[j + 1][k])
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }

    // Print the sorted array
    printf("Sorted Array (Descending): ");
    for (i = 0; i < 5; i++)
    {
        printf("%s ", arr[i]);
    }
    printf("\n");

    // 3 & 4: Find shortest and longest strings by scanning the array
    char *s = arr[0];
    char *l = arr[0];

    for (i = 1; i < 5; i++)
    {
        if (strlen(arr[i]) < strlen(s))
        {
            s = arr[i];
        }
        if (strlen(arr[i]) > strlen(l))
        {
            l = arr[i];
        }
    }

    // Print final results
    printf("Shortest String: %s\n", s);
    printf("Longest String: %s\n", l);
    printf("Total Comparisons: %d\n", cmp_count);

    return 0;
}
