#include <stdio.h>
// wap to compare 2 strings without using strcmp function.
int main()
{
    char str1[50], str2[50];
    int i, flag = 0;

    printf("Enter str1: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter str2: ");
    fgets(str2, sizeof(str2), stdin);

    for (i = 0; str1[i] != '\n' && str2[i] != '\n'; i++)
    {
        if (str1[i] != str2[i])
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0 && str1[i] == '\n' && str2[i] == '\n')
    {
        printf("strings are equal.\n");
    }
    else
    {
        printf("strings are not equal.");
    }
    return 0;
}