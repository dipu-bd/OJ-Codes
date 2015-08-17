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
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<int> vii;
typedef vector<pii> vpii;
typedef map<int, int> mpii;
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
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
#define TEMPLATE template<typename T>
//variables and functions
const double EPS = 1E-10;
const double PI = 2.0 * acos(0.0);
TEMPLATE inline T sqr(T n) { return n * n; }
TEMPLATE inline T pmod(T n, T m) { return ((n % m) + m) % m; }
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, ll p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
TEMPLATE T bigmod(T n, ll p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
TEMPLATE T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

const int oo = 1 << 30;
const int mod = 1000000007;

int test, cas = 1;

struct bridge
{
    ll v;
    int p;
    bridge() { }
    bridge(ll a, int i) : v(a), p(i) { }
    bool operator < (const bridge& r) const
    {
        return v < r.v || (v == r.v && p < r.p);
    }
};

struct island
{
    int p;
    ll mini;
    ll maxi;
    bool operator < (const island& r) const
    {
        return maxi < r.maxi;
    }
    bool isfit(const bridge& b) const
    {
        return mini <= b.v && b.v <= maxi;
    }
};

int n, m;
int res[200005];
vector<island> arr;
set<bridge> brr;

int main()
{
    scanf("%d %d", &n, &m);

    ll px, py, x, y;
    scanf("%I64d %I64d", &px, &py);
    REP(i, 1, n)
    {
        scanf("%I64d %I64d", &x, &y);
        island s;
        s.p = i;
        s.mini = x - py;
        s.maxi = y - px;
        arr.pb(s);
        px = x;
        py = y;
    }
    ssort(arr);

    REPE(i, 1, m)
    {
        bridge b;
        b.p = i;
        scanf("%I64d", &b.v);
        brr.ins(b);
    }

    bool pos = true;
    loop(it, arr)
    {
        island& s = *it;
        set<bridge>::IT jt = brr.lower_bound(bridge(s.mini, 0));
        if(jt == brr.end() || jt->v > s.maxi)
        {
            pos = false;
            break;
        }
        else
        {
            res[s.p] = jt->p;
            brr.erase(jt);
        }
    }

    if(pos)
    {
        puts("Yes");
        printf("%d", res[1]);
        REP(i, 2, n)
        printf(" %d", res[i]);
        putchar('\n');
    }
    else puts("No");


    return 0;
}
