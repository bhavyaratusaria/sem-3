#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int freq[200] = {0}, i;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\n'; i++)
    {
        freq[(unsigned char)str[i]]++;
    }

    printf("Character frequencies:\n");
    for (i = 0; i < 200; i++)
    {
        if (freq[i] > 0)
        {
            printf("'%c': %d\n", i, freq[i]);
        }
    }
    return 0;
}