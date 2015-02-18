#include <stdio.h>
#include <math.h>
#include <string.h>

#define SIZE 10100
char inp[SIZE];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("11716_Digital Fortress_01.inp", "r", stdin);
#endif

    double sq;
    int t, i, j, l, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf(" %[^\n]", inp);

        l = strlen(inp);
        sq = sqrt(l);
        m = sq;
        if(sq == m)
        {
            for(i = 0; i < m; ++i)
                for(j = i; j < l; j += m)
                    putchar(inp[j]);
            putchar('\n');
        }
        else puts("INVALID");
    }

    return 0;
}
