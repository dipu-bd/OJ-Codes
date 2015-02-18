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
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
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
/*--------------------------------------------------------------------------------------------------*/

#define MOD 1000000009

ll ncr[515][9];
ll save[515][515][9];

ll comb(int n, int r)
{
    if(r == 0 || r == n) return 1;

    ll& dp = ncr[n][r];
    if(dp != 0) return dp;

    dp = (comb(n - 1, r) + comb(n - 1, r - 1)) % MOD;

    return dp;
}

ll recur(int d, int rem, int k) //d = dept, rem = remaining nodes
{
    if(rem == 0) return 1LL;
    if(d == 0) return 0LL;

    ll& dp = save[d][rem][k];
    if(dp != -1) return dp;

    dp = 0;
    int l = min(k, rem);
    REPE(i, 0, l) dp = ((recur(d - 1, rem - i, k) * comb(rem, i)) % MOD + dp) % MOD;

    return dp;
}

int main()
{
    mem(save, -1);
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        int d, k, p, q;
        scanf("%d %d", &d, &k);

        ll sum = 1;
        scanf("%d", &p);
        while(d--)
        {
            scanf("%d", &q);
            sum = (sum * recur(p, q, k)) % MOD;
            p = q;
        }

        printf("Case %d: %lld\n", cas++, sum);
    }

    return 0;
}
