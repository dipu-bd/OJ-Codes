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
typedef unsigned long long ull;
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
#define LB lower_bound
#define UB upper_bound
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

int mod = 1000;
#define dim 3

ll mat[dim][dim];
ll ans[dim][dim];
ll tmp[dim][dim];

void UNIT()
{
    clr(ans);
    REP(i, 0, dim) ans[i][i] = 1;
}

void COPY(ll A[dim][dim])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    ans[i][j] = A[i][j];
}

void CROSS(ll A[dim][dim])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    {
        tmp[i][j] = 0;
        REP(k, 0, dim)
        {
            tmp[i][j] += ans[i][k] * A[k][j];
            tmp[i][j] %= mod;
        }
    }
    COPY(tmp);
}

void POWER(ll p)
{
    if(p == 0) UNIT();
    else if(p == 1) COPY(mat);
    else
    {
        POWER(p >> 1);
        CROSS(ans);
        if(p & 1) CROSS(mat);
    }
}

void init()
{
    clr(mat);
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[0][2] = 1;
    mat[1][0] = 1;
    mat[2][2] = 1;
}

int main()
{
#ifdef LOCAL
    freopen("10518.inp", "r", stdin);
#endif // LOCAL

    ll n;
    while(scanf("%lld %d", &n, &mod) != EOF)
    {
        if(n == 0 && mod == 0) break;

        init();
        POWER(n);

        ll res = 0;
        REP(i, 0, dim)
        {
            res += ans[1][i];
            res %= mod;
        }

        printf("Case %d: %lld %d %lld\n", cas++, n, mod, res);
    }

    return 0;
}
