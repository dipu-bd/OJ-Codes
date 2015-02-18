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

#define dim 6
int mod = 25000;

int res[dim][dim];
int tmp[dim][dim];
int mat[dim][dim];
int unit[dim][dim];
int a[3], b[3], c[3];
int f[3], g[3], A[dim];

void COPY(int T[dim][dim])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    res[i][j] = T[i][j];
}

void cross(int TA[dim][dim], int TB[dim][dim])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    {
        tmp[i][j] = 0;
        REP(k, 0, dim)
        tmp[i][j] = (tmp[i][j] + (TA[i][k] * TB[k][j]) % mod) % mod;
    }

    COPY(tmp);
}

void power(int n)
{
    if(n == 0) COPY(unit);
    else if(n == 1) COPY(mat);
    else
    {
        power(n >> 1);
        cross(res, res);
        if(n & 1) cross(res, mat);
    }
}

void precalc()
{
    clr(unit);
    REP(i, 0, dim) unit[i][i] = 1;
}

void init()
{
    clr(mat);
    mat[0][0] = a[1];
    mat[0][1] = b[1];
    mat[0][2] = c[1];
    mat[1][0] = 1;
    mat[2][4] = 1;
    mat[3][3] = a[2];
    mat[3][4] = b[2];
    mat[3][5] = c[2];
    mat[4][3] = 1;
    mat[5][1] = 1;

    A[0] = f[2];
    A[1] = f[1];
    A[2] = g[0];
    A[3] = g[2];
    A[4] = g[1];
    A[5] = f[0];
}

int main()
{
#ifdef LOCAL
    freopen("1131.inp", "r", stdin);
#endif // LOCAL

    precalc();
    int q, n;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d", a + 1, b + 1, c + 1);
        scanf("%d %d %d", a + 2, b + 2, c + 2);
        scanf("%d %d %d", f + 0, f + 1, f + 2);
        scanf("%d %d %d", g + 0, g + 1, g + 2);
        scanf("%d", &mod);

        init();
        printf("Case %d:\n", cas++);

        scanf("%d", &q);
        while(q--)
        {
            scanf("%d", &n);

            power(n);
            int fn = 0;
            int gn = 0;
            REP(i, 0, dim)
            {
                fn = (fn + A[i] * res[5][i]) % mod;
                gn = (gn + A[i] * res[2][i]) % mod;
            }

            printf("%d %d\n", fn, gn);
        }
    }

    n = __builtin_popcount(12312);

    return 0;
}
