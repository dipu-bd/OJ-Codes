#include <stdio.h>

int main()
{
    int a, b, c, d, l, f, x, n;
    while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &l)!=EOF && d>0)
    {
        for(x=n=0; x<=l; ++x)
        {
            f = (a*x + b)*x + c;
            if(f == f/d * d) ++n;
        }

        printf("%d\n",n);
    }

    return 0;
}

/*
0 0 10 5 100
0 0 10 6 100
1 2 3 4 5
1 2 3 3 5
1000 1000 1000 1000000 1000
0 0 0 0 0

*/
