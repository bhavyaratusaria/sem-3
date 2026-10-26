#include <stdio.h>

int main()
{
    int string[10];
    printf("Enter 10 reference string:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &string[i]);
    }
    int pf = 0;
    int f = 3;
    int temp[3];
    int index = 0;

    for (int i = 0; i < 3; i++)
    {
        temp[i] = -1;
    }

    printf("Stream | Frame 1 | Frame 2 | Frame 3 | Status\n");

    for (int i = 0; i < 10; i++)
    {
        int Hit = 0;

        for (int j = 0; j < 3; j++)
        {
            if (string[i] == temp[j])
            {
                Hit = 1;
                break;
            }
        }

        if (Hit == 0)
        {
            temp[index] = string[i];
            index = index + 1;
            if (index == f)
            {
                index = 0;
            }
            pf = pf + 1;
        }

        printf(" %d   |", string[i]);
        for (int j = 0; j < 3; j++)
        {
            if (temp[j] == -1)
            {
                printf("  -   |");
            }
            else
            {
                printf("  %d   |", temp[j]);
            }
        }

        if (Hit == 1)
        {
            printf(" Hit\n");
        }
        else
        {
            printf(" Fault\n");
        }
    }

    printf("Page Faults: %d\n", pf);
    printf("Page Hits: %d\n", 10 - pf);
    printf("Hit Ratio: %.2f\n", (10 - pf) / 10);
    return 0;
}
