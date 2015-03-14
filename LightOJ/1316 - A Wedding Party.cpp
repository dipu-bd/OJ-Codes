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
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
TEMPLATE T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

const int oo = 1 << 30;
const int mod = 1000000007;

typedef typedef pair<int, ll> pil;

int test, cas = 1;

struct edge
{
    int u, w;
    edge(int x = 0, int y = 0) : u(x), w(y) { }

    bool operator < (const edge& r) const
    {
        return r.w > w;
    }
};

int n, m, s;
int dis[505];
vpii graph[505];
int didis[18][18];
map<int, int> shop;
pil save[17][1 << 17];
int _save[17][1 << 17];

int dijkstra(int source, int sink)
{
    if(source == sink) return 0;
    priority_queue<edge> pq;
    pq.push(edge(source, 0));
    REPE(i, 0, n) dis[i] = oo;
    dis[source] = 0;
    while(pq.size())
    {
        edge e = pq.top();
        pq.pop();

        if(e.u == sink) return e.w;

        loop(it, graph[e.u])
        {
            int v = it->fr;
            int w = it->sc + e.w;
            if(w < dis[v])
            {
                dis[v] = w;
                pq.push(edge(v, w));
            }
        }
    }
    return oo;
}

pil recur(int p, int bit)
{
    pii& dp = save[p][bit];
    int& dpc = _save[p][bit];
    if(dpc == cas) return dp;

    dpc = cas;
    dp.fr = 0; //POPC(bit) - 2;
    dp.sc = didis[p][s];
//    printf("%d->%d, %d %d\n", p, s, dp.fr, dp.sc);

    REP(i, 0, s)
    if(!(bit & (1 << i)))
    {
        pii r = recur(i, bit | (1 << i));
        ++r.fr;
        if(r.sc < oo) r.sc += didis[p][i];

        if(dp.fr == r.fr)
        {
            dp.sc = min(dp.sc, r.sc);
        }
        else if(r.sc < oo && r.fr > dp.fr)
        {
            dp = r;
        }
    }

    return dp;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int u, v, w;

    sf1(test);
    while(test--)
    {
        sf3(n, m, s);

        REP(i, 0, n)
        graph[i].clear();

        //get ship locations
        shop[0] = 0; //source
        REPE(i, 1, s)
        {
            sf1(shop[i]);
        }
        shop[++s] = n - 1; //sink

        //get unidirectional graph
        REP(i, 0, m)
        {
            sf3(u, v, w);
            graph[u].pb(mp(v, w));
        }

        //build all dijkstra values
        REP(i, 0, s)
        REPE(j, 0, s)
        didis[i][j] = dijkstra(shop[i], shop[j]);

        //calculate result
        pii res = recur(0, 1 | (1 << s));
        printf("Case %d: ", cas++);
        if(res.sc >= oo) printf("Impossible\n");
        else  printf("%d %d\n", res.fr, res.sc);
    }

    return 0;
}
