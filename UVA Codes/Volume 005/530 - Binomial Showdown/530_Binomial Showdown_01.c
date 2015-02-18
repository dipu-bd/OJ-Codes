#include <stdio.h>

int main()
{
    int n,r;
    while(scanf("%d %d",&n,&r)==2 && n>0)
        comb(n,r);

    return 0;
}

void comb(int n, int r)
{
    int p = n-r;
    if(p<r) r=p;

    double res = 1;
    while(r>0)
    {
        res *= (double)n/r;
        --n, --r;
    }
    printf("%.0lf\n", res);
    return;
}
