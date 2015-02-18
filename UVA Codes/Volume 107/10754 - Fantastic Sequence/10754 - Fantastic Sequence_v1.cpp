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
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i >= n; --i)
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

#define DIM 30
#define SEP 1000000

int dim;
ll mod;
ll base[DIM];
ll coef[DIM];
ll mat[DIM][DIM];
ll ans[DIM][DIM];
ll tmp[DIM][DIM];

void UNIT()
{
    clr(ans);
    REP(i, 0, dim) ans[i][i] = 1;
}

void COPY(ll A[DIM][DIM])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    ans[i][j] = A[i][j];
}

void CROSS(ll A[DIM][DIM])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    {
        tmp[i][j] = 0;
        REP(k, 0, dim)
        {
            tmp[i][j] += (ans[i][k] * A[k][j]) % mod;
            tmp[i][j] %= mod;
        }
    }
    COPY(tmp);
}

void power(ll n)
{
    if(n == 0) UNIT();
    else if(n == 1) COPY(mat);
    else
    {
        power(n >> 1);
        CROSS(ans);
        if(n & 1) CROSS(mat);
    }
}

void init(int k)
{
    clr(mat);
    dim = k + 1;

    mat[0][0] = 1;
    mat[k][0] = 1;
    REP(i, 1, k) mat[i][i + 1] = 1;
    RREP(i, k, 1) mat[k][i] = coef[k - i];

    base[0] = coef[k];
}

ll pmod(ll n)
{
    n %= mod;
    if(n < 0) n += mod;
    return n;
}

ll func(ll n, int k)
{
    if(k == 0) return pmod(coef[0]);

    init(k);
    power(n);

    ll res = 0;
    REP(i, 0, dim)
    {
        res += (base[i] * ans[1][i]) % mod;
        res %= mod;
    }

    return pmod(res);
}

int main()
{
#ifdef LOCAL
    freopen("10754.inp", "r", stdin);
#endif // LOCAL

    ll n;
    int k;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %lld %lld", &k, &mod, &n);
        REPE(i, 0, k) scanf("%lld", coef + i);
        REPE(i, 1, k) scanf("%lld", base + i);

        printf("%lld\n", func(n, k));
        if(test) putchar('\n');
    }

    return 0;
}

/*
input:
15
0 100 0
354

2 10 10
1 1 0
1 1

2 1000 0
1 1 1
-10 -10

ouput:
54

*/
