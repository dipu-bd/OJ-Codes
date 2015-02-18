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
#include <list>
//#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 1013
vii prime;
bool flag[SIZ + 10];

void sieve()
{
    prime.pb(2);
    for(int i = 3; i <= SIZ; i += 2)
    {
        if(!flag[i])
        {
            prime.pb(i);
            for(int j = i * i; j <= SIZ; j += i + i)
                flag[j] = 1;
        }
    }
}

int ways[1010][1010];

int recur(int s, int t)
{
    if(s > t) return -1;
    if(s == t) return 0;

    int& dp = ways[s][t];
    if(dp) return dp;

    dp = INT_MAX;
    loop(p, prime)
    {
        if(*p >= s) break;
        if(!(s % (*p)))
        {
            int x = recur(s + *p, t);
            if(x != -1) dp = min(dp, x + 1);
        }
    }

    if(dp == INT_MAX) dp = -1;
    return dp;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int s, t;

    sieve();

    while(scanf("%d %d", &s, &t) != EOF && s && t)
    {
        printf("Case %d: %d\n", cas++, recur(s, t));
    }

    return 0;
}
