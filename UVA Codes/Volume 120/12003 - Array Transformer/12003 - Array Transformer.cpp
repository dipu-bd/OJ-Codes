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
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p>>1)); if(p&1) res*=n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
TEMPLATE T exgcd(T a,T b,T& x,T& y) { if(!b) { x=1; y=0; return a; } else { T g = exgcd(b, a%b, y, x); y -= (a/b)*x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 300004

ll u, v;
int l, r, p;
int n, m, b;
ll arr[SIZ];
vector<pll> buk[550];

inline bool compare(const pll& a, const pll& b)
{
    return a.fr < b.fr;
}

inline ll getcnt(vector<pll>& pv, ll x)
{
    return (ll)(LB(all(pv), mp(x, 0LL), compare) - pv.begin());
}

inline ll query(int l, int r, ll x)
{
    int sb = (l / b) + (l % b != 0); //starting bucket
    int eb = (r / b);  //ending bucket

    //get counts in buckets
    ll k = 0;
    REP(i, sb, eb)
    {
        k += getcnt(buk[i], x);
    }
    
    //get count around buckets
    RREPE(i, sb * b - 1, l)
    {
        if(arr[i] < x) ++k;
    }
    REPE(i, eb * b, r)
    {
        if(arr[i] < x) ++k;
    }
    
    return k;
}

inline void update(int p, ll x)
{
    //update in array
    arr[p] = x;
    
    //update in bucket
    int t = 0;
    vector<pll>& vp = buk[p / b];
    REP(i, 0, b)
    {
        if(vp[i].sc == p)
        {
            vp[i].fr = x;
            t = i;
            break;
        }
    }
    
    //rearrage
    while(t > 0 && vp[t].fr < vp[t - 1].fr) { swap(vp[t], vp[t - 1]); --t; }
    while(t + 1 < b && vp[t].fr > vp[t + 1].fr) { swap(vp[t], vp[t + 1]); ++t; }
}

int main()
{
    scanf("%d %d %lld", &n, &m, &u);
    
    //take numbers
    b = sqrt(n);
    REP(i, 0, n) 
    {
        scanf("%lld", &arr[i]);
        buk[i / b].pb(mp(arr[i], i));
    }
    
    //sort buckets
    RREPE(i, n / b - 1, 0) 
    stable_sort(all(buk[i]), compare);
    
    //run queries
    REP(i, 0, m)
    {
        scanf("%d %d %lld %d", &l, &r, &v, &p);
        ll k = query(l - 1, r - 1, v);
        update(p - 1, (u * k) / (r - l + 1)); 
    }
    
    //show result
    REP(i, 0, n)
    printf("%lld\n", arr[i]);
    
    return 0;
}