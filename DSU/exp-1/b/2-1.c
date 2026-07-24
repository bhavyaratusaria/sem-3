#include <stdio.h>
#include <string.h>

int main()
{
    char str[50] = "bhahb";
    int i, len = 0;

    printf("string: %s\n", str);

    if (strcmp(str, strrev(str)) == 0)
    {
        printf("palindrome");
    }
    else
    {
        printf("not a palindrome");
    }
    return 0;
}