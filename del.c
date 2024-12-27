//Deletion of elements in array
#include <stdio.h>
#define MAX 100
int main(int argc, char const *argv[])
{
    int n, size, arr[MAX];
    char dec;

    printf("Enter the size of the array ( 100 max ) : ");
    scanf("%d", &size);

    while (size > 100)
    {
        printf("Try again\n");
        printf("Please enter size within the bound limit ( 100 max): ");
        scanf("%d", &size);
    }

    for (size_t i = 0; i < size; i++)
    {
        printf("Enter the value of %zu index: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("Enter the element you want to del( 1-based ): ");
        scanf("%d", &n);

        while (n > size)
        {
            printf("The element does not exist\n");
            printf("try again: ");
            scanf("%d", &n);
        }

        for (int i = --n; i < size; n++, i++)
        {
            arr[n] = arr[n + 1];
            arr[n + 1] = 0;
        }
        size--;

        printf("The array after deletion is: ");
        for (size_t i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n Do you want to delete any other element ( y/n ): ");
        scanf(" %c", &dec);

    } while (dec == 'Y' || dec == 'y');

    return 0;
}
