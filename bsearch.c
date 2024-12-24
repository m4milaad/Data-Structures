#include <stdio.h>

int bs(int arr[], int low, int high, int key)
{
    int mid;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 4, 6, 8, 9, 10, 13, 17, 21, 36, 41, 47, 51, 57, 59, 62, 64, 68, 73, 75, 79};
    int low = 0, high = sizeof(arr) / sizeof(arr[0]);
    int key = 62;
    int result = bs(arr, low, high - 1, key);
    if (result == -1)
    {
        printf("Element not present\n");
    }
    else
        printf("Element is present at %d\n", result);
    return 0;
}
