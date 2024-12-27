//Mergeing 2 arrays
#include <stdio.h>
#define MAX 100

int main()
{
    int arr1[MAX], arr2[MAX], merge[MAX * 2];
    int sa1, sa2, ms;

    printf("Enter the size of array 1 (max %d): ", MAX);
    scanf("%d", &sa1);
    while (sa1 <= 0 || sa1 > MAX)
    {
        printf("Invalid size.\nEnter a size within the bound limit (1 to %d): ", MAX);
        scanf("%d", &sa1);
    }

    for (size_t i = 0; i < sa1; i++)
    {
        printf("Enter the value of %zu index: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of array 2 (max %d): ", MAX);
    scanf("%d", &sa2);
    while (sa2 <= 0 || sa2 > MAX)
    {
        printf("Invalid size.\nEnter a size within the bound limit (1 to %d): ", MAX);
        scanf("%d", &sa2);
    }

    for (size_t i = 0; i < sa2; i++)
    {
        printf("Enter the value of %zu index: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    ms = sa1 + sa2;
    for (size_t i = 0; i < sa1; i++)
    {
        merge[i] = arr1[i];
    }
    for (int i = 0; i < sa2; i++)
    {
        merge[sa1 + i] = arr2[i];
    }

    printf("The merged array is:\n");
    for (int i = 0; i < ms; i++)
    {
        printf("%d ", merge[i]);
    }
    printf("\n");

    return 0;
}
