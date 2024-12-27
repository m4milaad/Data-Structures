#include <stdio.h>

int main()
{
    // your code goes here
    int n, x;
    int t;

    scanf("%d", &t);
    if (t < 1 || t > 1000)
    {
        return 1;
    }

    while (t--)
    {
        scanf("%d %d", &n, &x);

        if (n < 1 || n > 100 || x < 1 || x > 1000)
        {
            return 1;
        }
        if (n <= 6)
        {
            printf("%d\n", n * x);
        }
        else if (n > 6)
        {
            if (n % 6 != 0)
                n = (n / 6) + 1;

            else
            {
                n /= 6;
            }
            printf("%d\n", n * x);
        }
    }
}
