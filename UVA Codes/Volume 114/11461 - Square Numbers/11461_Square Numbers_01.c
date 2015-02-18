#include <stdio.h>
#include <math.h>

int main()
{
    int a,b;
    while(scanf(" %d %d",&a,&b)==2 && a>0 && b>0)
        printf("%d\n",getsqr(a,b));
    return 0;
}

int getsqr(register a, register b)
{
    register int r,s;
    register float p;
    r = sqrt(b);
    p = sqrt(a);
    s = (int)p;
    r -= s - (p==s);
    return r;
}
