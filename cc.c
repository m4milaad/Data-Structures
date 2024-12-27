#include <stdio.h>
int main()
{
    // your code goes here

    int n, m;
    scanf("%d %d", &n, &m);
    int arrA[n], arrB[n];
    int fact = 1;
    for (int i = m; i != 0; i--)
        fact *= i;
    for (int i = 0; i < n; i++){
        scanf("%d", &arrA[i]);
        arrB[i] = arrA[i] * fact;
    }
    int count;
    for (int i = 0; i < n; i++){
        count = 0;
        for (int j = 1; j <= arrB[i]; j++){
            if (arrB[i] % j == 0)
                count++;
        }
        printf("%d ", count);
    }
}