#include <stdio.h>

int main()
{
    unsigned int a,b,x;
    while(scanf("%u %u",&a,&b)==2)
    {
        x = (b & ~a) | (a & ~b);
        printf("%d\n",x);
    }
    return 0;
}
