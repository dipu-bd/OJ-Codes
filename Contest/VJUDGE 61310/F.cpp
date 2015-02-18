/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
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
const double EPS = 1E-10;
const double PI = 2.0 * acos(0.0);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> T power(T n, int p) { return (p == 0) ? (T)(1) : (sqr(power(n, p >> 1)) * ((p & 1) * (n - 1) + 1)); }
template<typename T> T bigmod(T n, int p, T m) { return (p == 0) ? (T)(1) : ((sqr(bigmod(n, p >> 1, m)) % m) * ((p & 1) * (n - 1) % m + 1)) % m; }
template<typename T> T GCD(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

int p, w, h, s, d;
pii arr[30];
ll save[21][1048580];
int stcas[21][1048580];

ll recur(int v, int bit = 0)
{
    ll& dp = save[v][bit];
    int& cs = stcas[v][bit];
    if(cs == cas) return dp;

    cs = cas;
    dp = INT_MAX;
    bool bs = true;
    REP(i, 1, p)
    {
        if(bit & (1 << i)) continue;
        ll tm = abs(arr[v].fr - arr[i].fr) +
                abs(arr[v].sc - arr[i].sc);
        dp = min(dp, tm + recur(i, bit | (1 << i)));
        bs = false;
    }

    if(bs) dp = abs(arr[v].fr - arr[0].fr) +
                    abs(arr[v].sc - arr[0].sc);
    return dp;
}

bool comp(const pii& a, const pii& b)
{
    return  a.fr + a.sc < b.fr + b.sc;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    sf1(test);
    while(test--)
    {
        sf1(p);
        sf4(w, h, s, d);
        REP(i, 0, p)
        {
            sf2(arr[i].fr, arr[i].sc);
            arr[i].fr *= w;
            arr[i].sc *= h;
        }

        sort(arr + 1, arr + n, comp);

        ll r = INT_MAX;
        int mini = arr[1].fr + arr[1].sc;
        REP(i, 0,p)
        {
            int cur = arr[i].fr + arr[i].sc;
            if(cur > mini) break;
            r = min(r, recur(-1, ))
        }

        r = r / s + (ll)(p) * d;

        int mm = r % 60;
        int hh = r / 60 + 18;

        printf("%.2d:%.2d\n", hh, mm);
    }

    return 0;
}

/*
2
4
1 1 10 1
0 0
10 10
10 0
0 10
4
2 1 1 2
0 5
6 0
10 5
5 10
*/
