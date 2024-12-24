// adding elements in array
#include <stdio.h>
#define MAX 100

int main(int argc, char const *argv[])
{
    int r, n, size, arr[MAX];
    char dec;

    printf("Enter the size of the array (100 max): ");
    scanf("%d", &size);

    while (size <= 0 || size > MAX)
    {
        printf("Invalid size. Please enter a size within the bound limit (1 to %d): ", MAX);
        scanf("%d", &size);
    }

    for (int i = 0; i < size; i++)
    {
        printf("Enter the value for index %d: ", i);
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("Enter the index where you want to insert an element (1-based index): ");
        scanf("%d", &n);

        while (n < 1 || n > size + 1)
        {
            printf("Invalid index. Please enter a valid index (1 to %d): ", size + 1);
            scanf("%d", &n);
        }

        printf("Enter the element you want to add: ");
        scanf("%d", &r);

        for (int i = size; i >= n; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[n - 1] = r;
        size++;

        printf("The array after insertion is: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Do you want to add any other element (y/n)? ");
        scanf(" %c", &dec);

    } while (dec == 'Y' || dec == 'y');

    return 0;
}
