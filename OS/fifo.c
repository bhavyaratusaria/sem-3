#include <stdio.h>

int main()
{
    int n = 5; // Number of processes
    int m = 3; // Number of resources

    int alloc[5][3] = {
        {0, 1, 0}, // P0
        {2, 0, 0}, // P1
        {3, 0, 2}, // P2
        {2, 1, 1}, // P3
        {0, 0, 2}  // P4
    };

    int max[5][3] = {
        {7, 5, 3}, // P0
        {3, 2, 2}, // P1
        {9, 0, 2}, // P2
        {2, 2, 2}, // P3
        {4, 3, 3}  // P4
    };

    int avail[3] = {3, 3, 2};

    int finish[5] = {0, 0, 0, 0, 0};
    int safe_sequence[5];
    int index = 0;
    int need[5][3];

    // 1. Calculate the Remaining Need Matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // 2. Print the Initial Matrix Table
    printf("=========================== INITIAL STATE MATRIX ===========================\n");
    printf("Process\t  Allocation\t\tMax\t\tNeed\t\tAvailable\n");
    printf("=======\t  ==========\t\t===\t\t====\t\t=========\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t  ", i);

        // Print Allocation
        for (int j = 0; j < m; j++)
            printf("%d ", alloc[i][j]);
        printf("\t\t");

        // Print Max
        for (int j = 0; j < m; j++)
            printf("%d ", max[i][j]);
        printf("\t\t");

        // Print Need
        for (int j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\t\t");

        // Print Available only for the first row to keep it clean
        if (i == 0)
        {
            for (int j = 0; j < m; j++)
                printf("%d ", avail[j]);
        }
        printf("\n");
    }
    printf("\n");

    // 3. Step-by-Step Execution Trace Table Header
    printf("=========================== STEP-BY-STEP TRACE ===========================\n");
    printf("Process\tNeed\tAvailable\tCan Alloc?\tAction / New Available\n");
    printf("-------\t----\t---------\t----------\t----------------------\n");

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {

            if (finish[i] == 0)
            {
                int can_allocate = 1;

                // Print the current evaluation step details
                printf("P%d\t", i);
                for (int j = 0; j < m; j++)
                    printf("%d ", need[i][j]);
                printf("\t");
                for (int j = 0; j < m; j++)
                    printf("%d ", avail[j]);
                printf("\t");

                // Check resources
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        can_allocate = 0;
                        break;
                    }
                }

                if (can_allocate == 1)
                {
                    safe_sequence[index++] = i;

                    for (int j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j];
                    }

                    finish[i] = 1;

                    printf("YES\t\tFinishes -> New Avail: ");
                    for (int j = 0; j < m; j++)
                        printf("%d ", avail[j]);
                    printf("\n");
                }
                else
                {
                    printf("NO\t\tSkipped (Need > Available)\n");
                }
            }
        }
    }
    printf("\n");

    // 4. Final Verification and Sequence Output
    int system_is_safe = 1;
    for (int i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            system_is_safe = 0;
            break;
        }
    }

    printf("=========================== FINAL STATUS ===========================\n");
    if (system_is_safe == 1)
    {
        printf("RESULT: The system is in a SAFE STATE.\n");
        printf("SAFE SEQUENCE: ");
        for (int i = 0; i < n - 1; i++)
        {
            printf("P%d -> ", safe_sequence[i]);
        }
        printf("P%d\n", safe_sequence[n - 1]);
    }
    else
    {
        printf("RESULT: The system is UNSAFE (Deadlock danger detected).\n");
    }
    printf("====================================================================\n");

    return 0;
}
