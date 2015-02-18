/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
//#include <bits/stdc++.h>
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
//#include <assert.h>
//#include <time.h>
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
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<pii> vpii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//io
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
#define debug1(a) cout << a << endl
#define debug2(a,b) cout << a << " " << b << endl
#define debug3(a,b,c) cout << a << " " << b << " " << c << endl
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define allof(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
const double PI = 2.0 * acos(0.0);
const double EXP1 = exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> T power(T n, int p) { return (p == 0) ? (T)(1) : (sqr(power(n, p >> 1)) * ((p & 1) * (n - 1) + 1)); }
template<typename T> T bigmod(T n, int p, T m) { return (p == 0) ? (T)(1) : ((sqr(bigmod(n, p >> 1, m)) % m) * ((p & 1) * (n - 1) % m + 1)) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1, n;

#define MAX 1000001
int arr[100005];
int pos[MAX + 10];
bool vis[MAX + 10];
vii factor[MAX + 10];

void select(int n)
{
    vis[n] = 1;
    factor[n].pb(n);
    for(int i = n + n; i <= MAX; i += n)
    {
        vis[i] = 1;
        factor[i].pb(n);
    }
}

void sieve()
{
    select(2);
    for(int i = 3; i <= MAX; i += 2)
    {
        if(!vis[i]) select(i);
    }
}

int markall(int p)
{
    int m = 0;
    loop(i, factor[arr[p]])
    {
        if(m < pos[*i]) m = pos[*i];
        pos[*i] = p;
    }
    return m;
}

int main()
{
    #ifdef LOCAL
    //freopen("", "r", stdin);
    #endif // LOCAL

    sieve();

    sf1(test);
    while(test--)
    {
        sf1(n);
        REPE(i, 1, n) sf1(arr[i]);

        clr(pos);
        int mxcnt = 0;
        int beg = 0, cur;
        for(cur = 1; cur <= n; ++cur)
        {
            int m = markall(cur);
            if(m > beg) beg = m;
            mxcnt = max(mxcnt, cur - beg);
        }

        if(mxcnt == 1) puts("-1");
        else printf("%d\n", mxcnt);
    }

    return 0;
}
