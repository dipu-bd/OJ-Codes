#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

typedef long long ll;

int n, k, m;
ll save[55][55];

ll recur(int dept, int cnt)
{
    if(dept == k)
    {
        if(cnt == n) return 1;
        else return 0;
    }
    if(cnt > n) return 0;

    ll& dp = save[cnt][dept];
    if(dp != -1) return dp;

    ll t = 0;
    for(int i = 1; i <= m; ++i)
    {
        t += recur(dept + 1, cnt + i);
    }

    return (dp = t);
}

int main()
{
    while(scanf("%d %d %d", &n, &k, &m) != EOF)
    {
        memset(save, -1, sizeof(save));
        printf("%lld\n", recur(0, 0));
    }

    return 0;
}
