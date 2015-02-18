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

int m;
ll save[51][51][51];

ll BC(int n, int k)
{
    if(k == 0) return (n == 0);
    if(n <= 0) return 0;

    ll& dp = save[n][k][m];
    if(dp != -1) return dp;

    ll t = 0;
    for(int i = 1; i <= m; ++i)
        t += BC(n - i, k - 1);

    return (dp = t);
}

int main()
{
    int test, cas = 1;

    int n, k;
    memset(save, -1, sizeof(save));

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d", &n, &k, &m);
        printf("Case %d: %lld\n", cas++, BC(n, k));
    }

    return 0;
}
