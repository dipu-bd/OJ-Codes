#include <stdio.h>
#include <ctype.h>

int main()
{
    int i,t, a,b, p;
    double d;
    char inp[10];

    scanf("%d", &t);
    for(i=1; i<=t; ++i)
    {
        scanf(" %[^\n]", inp);

        for(p=a=0; isdigit(inp[p]) && inp[p]; ++p)
            a = 10*a + inp[p]-'0';

        while(inp[p] && !isdigit(inp[p])) p++;
        b = inp[p] ? inp[p]-'0' : 0;

        d = a*0.5 + b*0.05;

        printf("Case %d: %g\n", i, d);
    }

    return 0;
}
