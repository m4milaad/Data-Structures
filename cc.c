#include <stdio.h>

int main() {
    // your code goes here
    int n, t;
    scanf("%d", & t);
    while (t--)
    {
        scanf("%d", & n);

        if (n < 16)
        {
            if (n < 10 && n % 2 != 0)
                printf("Lower Double\n");
            else printf("Lower Single\n");
        }
        else
        {
            if(n<25&&n%2==0)
            printf("Upper Double\n");
            else printf("Lower Single\n");
        }

    }

}