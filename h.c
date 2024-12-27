#include <stdio.h>

void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r);
void prt_arr(int arr[], int size);

int main()
{
    int arr[] = {1, 2, 4, 65, 7, 7, 8, 5, 4, 4, 6, 54};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("the unsorted array is: ");
    prt_arr(arr, size);

    merge_sort(arr, 0, size - 1);
    printf("\nSorted array is: ");
    prt_arr(arr, size);
    return 0;
}
void merge(int arr[], int l, int m, int r)
{
    int s1, s2;
    s1 = m - l + 1;
    s2 = r - m;

    int a1[s1], a2[s2];

    for (size_t i = 0; i < s1; i++)
    {
        a1[i] = arr[l + i];
    }
    for (size_t i = 0; i < s2; i++)
    {
        a2[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < s1 && j < s2)
    {
        if (a1[i] <= a2[j])
        {
            arr[k] = a1[i];
            i++;
        }
        else
        {
            arr[k] = a2[j];
            j++;
        }
        k++;
    }

    while (i < s1)
    {
        arr[k] = a1[i];
        i++, k++;
    }
    while (j < s2)
    {
        arr[k] = a2[j];
        j++, k++;
    }
}
void merge_sort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = l + (r - l) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}
void prt_arr(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}