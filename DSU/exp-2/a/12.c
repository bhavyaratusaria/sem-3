#include <stdio.h>

int main()
{
    int n, pos;

    printf("Enter num: ");
    scanf("%d", &n);

    printf("Enter the bit position to toggle: ");
    scanf("%d", &pos);

    printf("\n--- Checking Bit at Position %d ---\n", pos);

    int mask = 1 << pos;
    int check = n & mask;

    if (check != 0)
    {
        printf("Bit at position %d is currently: SET (1)\n", pos);
    }
    else
    {
        printf("Bit at position %d is currently: CLEAR (0)\n", pos);
    }

    printf("\n--- Toggling Bit at Position %d ---\n", pos);

    int toggled = n ^ mask;

    printf("Original num: %d\n", n);
    printf("Number after toggling bit %d: %d\n", pos, toggled);

    printf("\n--- Counting Total Set Bits ---\n");

    int temp = n;
    int total_set_bits = 0;

    while (temp > 0)
    {
        if ((temp & 1) == 1)
        {
            total_set_bits++;
        }
        temp = temp >> 1;
    }

    printf("Total number of set bits (1s) in %d is: %d\n", n, total_set_bits);
    return 0;
}
