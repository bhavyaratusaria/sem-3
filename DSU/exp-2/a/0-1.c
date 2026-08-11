#include <stdio.h>

int main()
{
    int num, n;
    printf("Enter number: ");
    scanf("%d", &num);

    printf("Enter bit position: ");
    scanf("%d", &n);

    if ((num & (1 << n)) != 0)
    {
        printf("Bit at position %d is set.", n);
    }
    else
    {
        printf("Bit at position %d is clear.", n);
    }

    return 0;
}