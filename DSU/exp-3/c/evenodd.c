#include <stdio.h>
// Write a 'C' Program to Check Whether a Number is Even or Odd Using Bitwise Operator

int main()
{
    int num;
    printf("Enter Number: ");
    scanf("%d", &num);

    if ((num & 1) == 0)
    {
        printf("Number is Even.");
    }
    else
    {
        printf("Number is Odd.");
    }
    return 0;
}