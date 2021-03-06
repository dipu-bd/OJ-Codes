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
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

ll mat[2][2];
ll res[2][2];
ll tmp[2][2];

void COPY(ll A[2][2])
{
    res[0][0] = A[0][0];
    res[0][1] = A[0][1];
    res[1][0] = A[1][0];
    res[1][1] = A[1][1];
}

void cross(ll A[2][2])
{
    tmp[0][0] = res[0][0] * A[0][0] + res[0][1] * A[1][0];
    tmp[0][1] = res[0][0] * A[0][1] + res[0][1] * A[1][1];
    tmp[1][0] = res[1][0] * A[0][0] + res[1][1] * A[1][0];
    tmp[1][1] = res[1][0] * A[0][1] + res[1][1] * A[1][1];
    COPY(tmp);
}

void initmat(ll p, ll q)
{
    mat[0][0] = p;
    mat[0][1] = -q;
    mat[1][0] = 1;
    mat[1][1] = 0;
}

void power(ll n)
{
    if(n == 0)
    {
        res[0][0] = 1;
        res[0][1] = 0;
        res[1][0] = 0;
        res[1][1] = 1;
    }
    else if(n == 1)
    {
        COPY(mat);
    }
    else
    {
        power(n >> 1);
        cross(res);
        if(n & 1) cross(mat);
    }
}

char inp[100];

int main()
{
#ifdef LOCAL
    freopen("10655.inp", "r", stdin);
#endif // LOCAL

    ll p, q, n;

    while(scanf("%lld %lld", &p, &q) != EOF)
    {
        int scr = scanf("%lld", &n);
        if(p == 0 && q == 0 && scr == EOF) break;

        initmat(p, q);
        power(n);

        ll ans = p * res[1][0] + 2 * res[1][1];
        printf("%lld\n", ans);
    }

    return 0;
}
