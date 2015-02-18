#include <stdio.h>
#include <math.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("264_Count on Cantor_01.inp","r",stdin);
#endif

    int x,n,m,p,s;
    while(scanf("%d", &x)!=EOF)
    {
        n = (1 + sqrt(1+8*x))/2;
        m = x - n*(n-1)/2;

        if(m==0)
        {
            if(n&1) s=m+1, p=n-1;
            else p=m+1, s=n-1;
        }
        else
        {
            if(n&1) s=m, p=n-m+1;
            else p=m, s=n-m+1;
        }

        printf("TERM %d IS %d/%d\n",x,p,s);
    }

    return 0;
}
