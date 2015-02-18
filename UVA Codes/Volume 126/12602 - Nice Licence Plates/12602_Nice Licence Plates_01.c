#include <stdio.h>
#include <math.h>

int main()
{
    int n,c,d;
    char c1,c2,c3;
    scanf("%d",&n);
    for(;n>0 && scanf(" %c%c%c-%d",&c1,&c2,&c3,&d)==4;n--)
    {
        c=(c1-'A')*676+(c2-'A')*26+(c3-'A');
        d=abs(c-d);
        if(d<=100)
            printf("nice\n");
        else
            printf("not nice\n");
    }
    return 0;
}
