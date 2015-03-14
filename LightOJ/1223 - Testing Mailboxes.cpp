/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
//#include <bits/stdc++.h>
//C headers
#include <stdio.h>
#include <iostream>
using namespace std;
//always useful
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//io
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
/*------------------------------------------------------------------------------------*/

int test, cas = 1;
int save[101][101][101];

int recur(int k, int l, int r)
{
    if(l > r) return 0;

    int& dp = save[k][l][r];
    if(k == 1 || dp > 0) return dp;

    dp = 1000000000;
    REPE(i, l, r)
    dp = min(dp, i + max(recur(k - 1, l, i - 1), recur(k, i + 1, r)));

    return dp;
}

void buildup()
{

}

int main()
{
   REPE(l, 1, 100)
    REPE(r, l, 100)
    save[1][l][r] = ((r - l + 1) * (r + l)) >> 1;

    int k, n;
    sf1(test);
    while(test--)
    {
        sf2(k, n);
        printf("Case %d: %d\n", cas++, recur(k, 1, n));
    }

    return 0;
}
