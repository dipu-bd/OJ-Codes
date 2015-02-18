#include <stdio.h>

int main()
{
    int n;
    register i,s,t;
    while(scanf("%d",&n)==1 && n>0)
    {
        for(i=0;n>2;n=s+t,i+=s)
        {
            s=n/3;
            t=n-s*3;
        }
        if(n==2) i++;
        printf("%d\n",i);
    }
    return 0;
}
