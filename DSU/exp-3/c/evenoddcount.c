#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int even = 0, odd = 0;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int *ptr = (int *)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    for (i = 0; i < n; i++)
    {
        if ((ptr[i] & 1) == 0)
        {
            printf("%d is even.\n", ptr[i]);
            even++;
        }
        else
        {
            printf("%d is odd.\n", ptr[i]);
            odd++;
        }
    }
    printf("Even Numbers: %d\n", even);
    printf("Odd Numbers: %d", odd);

    free(ptr);
    return 0;
}
