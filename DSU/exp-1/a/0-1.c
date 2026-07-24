#include <stdio.h>

int main()
{
    int i, ins, pos, arr[6];

    printf("1: Create\n");
    printf("Enter 5 elements in the array: ");
    for (i = 0; i <= 4; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array: ");
    for (i = 0; i <= 4; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n2: Insert\n");
    printf("Enter position to insert element: ");
    scanf("%d", &pos);
    printf("Enter element to insert: ");
    scanf("%d", &ins);
    for (i = 4; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[pos] = ins;

    printf("Array: ");
    for (i = 0; i <= 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n3: Delete\n");
    printf("Enter position to delete element: ");
    scanf("%d", &pos);
    for (i = pos; i < 5; i++)
    {
        arr[i] = arr[i + 1];
    }

    printf("\n4: Display\n");
    printf("Array: ");
    for (i = 0; i <= 4; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}