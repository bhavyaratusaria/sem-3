#include <stdio.h>
// WAP to count even and odd elements in an array
int main()
{
    int arr[] = {1, 9, 44, 9, 82, 1};
    int even = 0, odd = 0, i;

    for (i = 0; i < 6; i++)
    {
        if ((arr[i] & 1) == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    printf("Even elements: %d\n", even);
    printf("Odd elements: %d", odd);
    return 0;
}
