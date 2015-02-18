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
typedef vector<int> vi;
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

int test, cas = 1;

int len;
char str[30];
char path[30];
ll save[(1 << 20) + 10];
int dpcas[(1 << 20) + 10];

ll recur(int bit = 0)
{
    ll& dp = save[bit];
    int& dpc = dpcas[bit];
    if(dpc == cas) return dp;

    dp = 0;
    dpc = cas;

    int m = 1;
    bool finish = true;
    for(int i = 0; i < len; ++i, m <<= 1)
    {
        if(!(bit & m))
        {
            if(i == 0 || str[i - 1] != str[i] || (bit & (m >> 1)))
            {
                dp += recur(bit | m);
                finish = false;
            }
        }
    }

    if(finish) dp = 1;
    return dp;
}

bool findpath(ll n, int p = 0, int bit = 0)
{
    if(p == len)
    {
        path[p] = 0;
        return true;
    }

    int m = 1;
    ll prev = 0, cnt = 0;
    for(int i = 0; i < len; ++i, m <<= 1)
    {
        if(!(bit & m))
        {
            if(i == 0 || str[i - 1] != str[i] || (bit & (m >> 1)))
            {
                cnt += recur(bit | m);
                if(cnt > n)
                {
                    path[p] = str[i];
                    findpath(n - prev, p + 1, bit | m);
                    return true;
                }
                prev = cnt;
            }
        }
    }

    return false;
}

int main()
{
    #ifdef LOCAL
    freopen("1060.inp", "r", stdin);
    //freopen("1060prog.out", "w", stdout);
    #endif // LOCAL

    ll n;
    sf1(test);
    while(test--)
    {
        scanf(" %s %lld", str, &n);
        len = strlen(str);
        sort(str, str + len);

        bool found = findpath(n - 1);

        printf("Case %d: ", cas++);
        if(found) puts(path);
        else puts("Impossible");
    }

    return 0;
}
