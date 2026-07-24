#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50] = "Hello", str2[50] = " World", str3[100];

    printf("strlen: Length of str1 (%s) is %d\n", str1, strlen(str1));

    printf("strcpy: str3 is %s\n", strcpy(str3, str1));

    printf("strcat: str3 is %s\n", strcat(str3, str2));

    printf("strcmp: comparing str1 & str2: %d\n", strcmp(str1, str2));

    printf("strchr: strchr for e is '%s'\n", strchr(str1, 'e'));

    printf("strupr: str1 is %s\n", strupr(str1));

    printf("strlwr: str1 is %s\n", strlwr(str1));

    printf("strrev: str1 is %s", strrev(str1));

    return 0;
}
