#include <stdio.h>

int main()
{
    int tc, a,b,m, res;
    scanf("%d",&tc);
    for(;tc>0;--tc)
    {
        scanf(" %d %d %d",&a,&b,&m);
        res = ((2*a-b)*m)/(a+b);
        printf("%d\n",res);
    }

}
