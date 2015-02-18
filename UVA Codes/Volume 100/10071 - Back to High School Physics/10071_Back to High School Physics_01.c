#include <stdio.h>

int main()
{
    long int v,t,s;
    long int res[100000], i=0;
    while(scanf("%ld %ld",&v,&t)==2)
    {
        s=2*v*t;
        res[i++] = s;
    }

    for(s=0;s<i;s++)
        printf("%ld\n",res[s]);

    return 0;
}
