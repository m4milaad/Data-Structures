//Finding Maximum and minimum of array
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int min, max, size;

    printf("Enter the size of an array: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter the value of element at %d index: ", i + 1);
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("MAX = %d\nMIN = %d\n", max, min);
    return 0;
}
