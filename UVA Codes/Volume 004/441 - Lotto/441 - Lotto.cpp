/* =================================
@AUTHOR : Sudipto Chandra Das DIPU
@UNIV : SUST [2012-331-019]
@COUNTRY : Bangladesh
================================= */
// C headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
// CPP headers
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>

int K;
int num[15];
bool check[15];
int par[15];

void showall(int p)
{
    if(par[p] == 0)
    {
        printf("%d", num[p]);
        return;
    }

    showall(par[p]);
    printf(" %d", num[p]);
}

void lotto(int p = 0, int n = 0)
{
    if(n == 6)
    {
        showall(p);
        putchar('\n');
        return;
    }

    for(int i = p + 1; i <= K; ++i)
    {
        if(!check[i])
        {
            check[i] = true;
            int q = par[i];
            par[i] = p;

            lotto(i, n + 1);
            check[i] = false;
            par[i] = q;
        }
    }
}

//main function
int main()
{
#ifdef DIPU
    freopen("441.inp", "r", stdin);
#endif // DIPU

    bool nl = false;
    while(scanf("%d", &K) != EOF && K)
    {
        if(nl) putchar('\n');
        else nl = true;

        for(int i = 1; i <= K; ++i)
            scanf("%d", num + i);

        lotto();
    }

    return 0;
}
