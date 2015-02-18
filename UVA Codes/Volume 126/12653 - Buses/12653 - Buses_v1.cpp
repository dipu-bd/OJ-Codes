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

const int dim = 2;
ll N, K, L, ans;
ll mod = 1000000;
ll mat[dim][dim];
ll res[dim][dim];
ll tmp[dim][dim];

void UNIT()
{
    clr(res);
    REP(i, 0, dim)
    res[i][i] = 1;
}

void COPY(ll A[dim][dim])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    res[i][j] = A[i][j];
}

void CROSS(ll A[dim][dim])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    {
        tmp[i][j] = 0;
        REP(k, 0, dim)
        tmp[i][j] += res[i][k] * A[k][j];
        tmp[i][j] %= mod;
    }
    COPY(tmp);
}

void POWER(ll n)
{
    if(n == 0) UNIT();
    else if(n == 1) COPY(mat);
    else
    {
        POWER(n >> 1);
        CROSS(res);
        if(n & 1) CROSS(mat);
    }
}

void init()
{
    K %= mod;
    L %= mod;

    clr(mat);
    mat[0][0] = 0;
    mat[0][1] = 1;
    mat[1][0] = L;
    mat[1][1] = K;
}

int main()
{
    #ifdef LOCAL
    //freopen("", "r", stdin);
    #endif // LOCAL

    while(scanf("%lld %lld %lld", &N, &K, &L) != EOF)
    {
        init();
        POWER((N / 5) - 1);

        ans = (K * res[0][0]) % mod;
        ans += (K * K + L) * res[0][1];
        ans %= mod;

        printf("%.6lld\n", ans);
    }

    return 0;
}
