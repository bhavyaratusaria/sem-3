#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[100], str2[100], ch;
    int len = 0, v = 0, c = 0, words = 0, in_word = 0, pal = 1;
    int freq[256] = {0}, i, diff;

    printf("Enter string 1: ");
    fgets(str, sizeof(str), stdin);

    while (str[len] != '\n')
        len++;

    for (i = 0; i < len; i++)
    {
        ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z')
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                v++;
            else
                c++;
        }

        if (str[i] == ' ')
            in_word = 0;
        else if (in_word == 0)
        {
            in_word = 1;
            words++;
        }

        freq[(unsigned char)str[i]]++;
    }

    for (i = 0; i < len / 2; i++)
    {
        if (tolower(str[i]) != tolower(str[len - 1 - i]))
        {
            pal = 0;
            break;
        }
    }

    printf("Enter string 2: ");
    fgets(str2, sizeof(str2), stdin);

    i = 0;
    while (str[i] != '\n' && str2[i] != '\n' && str[i] == str2[i])
        i++;
    diff = str[i] - str2[i];

    printf("\nVowels: %d, Consonants: %d\n", v, c);
    printf("Palindrome: %s\n", pal ? "Yes" : "No");
    printf("Words: %d\n", words);

    printf("Frequency:\n");
    for (i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
            printf("'%c': %d\n", i, freq[i]);
    }

    printf("Comparison: ");
    if (diff == 0)
        printf("Equal");
    else if (diff < 0)
        printf("String 1 is smaller");
    else
        printf("String 1 is larger");

    return 0;
}
