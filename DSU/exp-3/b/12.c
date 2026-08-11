#include <stdio.h>
#include <string.h>

int main()
{
    char string[100] = "the teacher showed the students a new book.";
    char find[20] = "the";

    char *ptr = string;
    int count = 0;

    printf("String: %s\n", string);
    printf("Find: %s\n", find);

    printf("Occurrences found at: ");

    while ((ptr = strstr(ptr, find)) != NULL)
    {
        int index = ptr - string + 1;
        printf("%d ", index);
        count++;
        ptr += strlen(find);
    }

    printf("\nTotal count of occurrences: %d\n", count);
    return 0;
}