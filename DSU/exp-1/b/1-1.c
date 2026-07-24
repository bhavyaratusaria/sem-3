#include <stdio.h>
#include <string.h>

int main()
{
    char str[50] = "Bhavya";
    int v = 0, c = 0;
    printf("string: %s\n", str);
    strlwr(str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            v++;
        }
        else
        {
            c++;
        }
    }

    printf("vowels: %d\n", v);
    printf("consonants: %d", c);
    return 0;
}