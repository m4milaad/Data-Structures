#include <stdio.h>

int main() {
	// your code goes here
    int a,b,c,d,t;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        int f,s;
        f=(a>b)?a:b;
        s=(c>d)?c:d;
        printf("%d\n",f+s);
        
    }
    
}

