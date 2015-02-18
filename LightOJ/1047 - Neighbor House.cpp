/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
//cpp headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vii;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define sf scanf
#define pf printf
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define FOR(i, a, n) for(int i = a; i < n; ++i)
#define RFOR(i, a, n) for(int i = a; i > n; --i)
#define FORE(i, a, n) for(int i = a; i <= n; ++i)
#define RFORE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(typ,it,v) for(typ::iterator it = v.begin(); it != v.end(); ++it)
#define cloop(typ,it,v) for(typ::const_iterator it = v.begin(); it != v.end(); ++it)
#define rloop(typ,it,v) for(typ::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
#define rcloop(typ,it,v) for(typ::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it)

int n;
int house[30][3];
int cost[30][3];

int min3(int a, int b, int c)
{
    return ((a < b && a < c) ? a : (b  < c ? b : c));
}

int recur(int p, int choice)
{
    if(p > n) return 0;

    int& dp = cost[p][choice];
    if(dp > 0) return dp;

    switch(choice)
    {
    case -1:
        return dp = min3(house[p][0] + recur(p + 1, 0),
                         house[p][1] + recur(p + 1, 1),
                         house[p][2] + recur(p + 1, 2));
    case 0:
        return dp = min(house[p][1] + recur(p + 1, 1),
                        house[p][2] + recur(p + 1, 2));
    case 1:
        return dp = min(house[p][0] + recur(p + 1, 0),
                        house[p][2] + recur(p + 1, 2));
    case 2:
        return dp = min(house[p][0] + recur(p + 1, 0),
                        house[p][1] + recur(p + 1, 1));
    }
}

int main()
{
    int test, cas = 1;
    sf("%d", &test);

    while(test--)
    {
        sf("%d", &n);
        FORE(i, 1, n)
        {
            sf("%d %d %d",
               &house[i][0], &house[i][1], &house[i][2]);
        }

        clr(cost);
        pf("Case %d: %d\n", cas++, recur(1, -1));
    }

    return 0;
}

