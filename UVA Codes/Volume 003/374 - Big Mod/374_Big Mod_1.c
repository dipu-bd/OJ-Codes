#include <stdio.h>

int bigmod(register,register,register);

int main()
{
    int b,p,m;
    register r;
    while(scanf("%d\n%d\n%d",&b,&p,&m)==3)
    {
        r=(b>0)?bigmod(b,p,m):0;
        printf("%d\n",r);
    }
    return 0;
}

int bigmod(register b,register e,register m)
{
    register r,s;
    for(r=1;e>0;e>>=1)
    {
        s = b%m;
        if(e & 0x1) r = (r*s)%m;
        b = (s*s)%m;
    }
    return r;
}
