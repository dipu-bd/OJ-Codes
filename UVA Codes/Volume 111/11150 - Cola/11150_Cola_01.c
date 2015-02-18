#include <stdio.h>

int main()
{
    int n,res,t;
    while(scanf("%d",&n)==1)
    {
        for(res=n;n>2;res+=t)
            n -= (t=n/3)*2;
        if(n==2) res++;
        printf("%d\n",res);
    }
    return 0;
}
