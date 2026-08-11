#include <stdio.h>

int main()
{
    int n, pos;

    printf("Enter num: ");
    scanf("%d", &n);

    printf("Enter bit position to toggle: ");
    scanf("%d", &pos);

    printf("\nChecking Bit\n");

    int mask = 1 << pos;
    int check = n & mask;

    if (check != 0)
    {
        printf("Bit is set (1)\n");
    }
    else
    {
        printf("Bit is clear (0)\n");
    }

    printf("\nToggling Bit\n");

    int toggled = n ^ mask;

    printf("Number after toggling bit at %d: %d\n", pos, toggled);

    printf("\nTotal Set Bits\n");

    int temp = n;
    int set_bits = 0;

    while (temp > 0)
    {
        if ((temp & 1) == 1)
        {
            set_bits++;
        }
        temp = temp >> 1;
    }

    printf("Total set bits in number is: %d\n", set_bits);
    return 0;
}
