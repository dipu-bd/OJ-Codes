#include <stdio.h>

int main()
{
    int tc,j;
    int e,f,c,t;
    scanf("%d",&tc);
    for(;tc>0;tc--)
    {
        scanf("%d %d %d",&e,&f,&c);
        for(t=0,e+=f; e>=c; e+=(e/c)*(1-c)) t+=e/c;
        printf("%d\n",t);
    }
    return 0;
}
