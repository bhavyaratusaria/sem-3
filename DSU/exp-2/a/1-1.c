#include <stdio.h>

int main()
{
    int num, n;

    printf("Enter num: ");
    scanf("%d", &num);

    printf("Enter the bit position to toggle: ");
    scanf("%d", &n);

    printf("\n--- Checking Bit at Position %d ---\n", n);

    // Create the mask by sliding 1 to the left 'n' times
    int mask = 1 << n;

    // Compare the num with our mask
    int check_result = num & mask;

    // If the result is NOT zero, that bit must be a 1
    if (check_result != 0)
    {
        printf("Bit at position %d is currently: SET (1)\n", n);
    }
    else
    {
        printf("Bit at position %d is currently: CLEAR (0)\n", n);
    }

    // 3. TOGGLE BIT (Rewritten to be ultra-simple)
    printf("\n--- Toggling Bit at Position %d ---\n", n);

    // XOR flips a 0 to 1, or a 1 to 0 at the mask position
    int toggled_num = num ^ mask;

    printf("Original num: %d\n", num);
    printf("Number after toggling bit %d: %d\n", n, toggled_num);

    // 4. COUNT SET BITS
    printf("\n--- Counting Total Set Bits ---\n");

    int temp = num; // Copy the original num so we don't destroy it
    int total_set_bits = 0;

    while (temp > 0)
    {
        // If the rightmost bit is 1, increase the count
        if ((temp & 1) == 1)
        {
            total_set_bits++; // Avoided the ++ shorthand
        }
        // Slide the num 1 position to the right to look at the next bit
        temp = temp >> 1;
    }

    printf("Total number of set bits (1s) in %d is: %d\n", num, total_set_bits);

    return 0;
}
