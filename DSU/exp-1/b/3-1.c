#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, words = 0;

    printf("Enter words: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\n'; i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\n')
        {
            words++;
        }
    }

    if (strlen(str) > 1 && str[0] != ' ')
    {
        words++;
    }
    printf("Number of words: %d\n", words);
    return 0;
}
