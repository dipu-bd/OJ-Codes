#include <stdio.h>
#include <math.h>

short c;
short last[50];

char isPseudoPrime(register short a, register short b)
{
    do
    {
        c = a;
        a = b;
        b = c%b;
    } while(b>0);

    return (a==1);
}

short main()
{
    short n, j, i, total,match;
    double res;

    while(scanf("%d",&n)!=EOF && n>0)
    {
        total = (n*(n-1))>>1;
        match = 0;
        for(i=0;i<n;++i)
        {
            scanf("%d",&last[i]);
            for(j=0;j<i;++j)
                if(isPseudoPrime(last[i],last[j])==1)
                    ++match;
        }

        res = sqrt(6.0*total/match);

        if(match) printf("%.6lf\n",res);
        else puts("No estimate for this data set.");
    }

    return 0;
}
