#include <stdio.h>
#include <string.h>

int main()
{
    char string[200] = "the quick brown fox jumps over the lazy dog near the well";
    char find[20] = "the";

    char *ptr = string;
    int count = 0;

    printf("String: %s\n", string);
    printf("Find: %s\n\n", find);

    printf("Occurrences found at: ");

    while ((ptr = strstr(ptr, find)) != NULL)
    {
        int index = ptr - string;
        printf("%d ", index);
        count++;
        ptr += strlen(find);
    }

    printf("\n Total count of occurrences: %d\n", count);

    return 0;
}