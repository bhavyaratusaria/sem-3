#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    int mid = (low + high) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, high, key);
    }
    else
    {
        return binarySearch(arr, low, mid - 1, key);
    }
}

int main()
{
    int arr[10], n, i, key, mid;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to find: ");
    scanf("%d", &key);

    mid = binarySearch(arr, 0, n - 1, key);

    printf("Element found at position: %d", mid);
    return 0;
}
