#include <stdio.h>

int main()
{
    int i,c, a,l;
    unsigned int n;

    for(i=1; scanf("%d %d", &a, &l)!=EOF && a>=0; ++i)
    {
        for(n=a, c=0; n>1 && n<=l; ++c)
            n = (1&n)? 3*n+1 : (n>>1);
        if(n<=1) ++c;
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n", i, a, l,c);
    }

    return 0;
}
