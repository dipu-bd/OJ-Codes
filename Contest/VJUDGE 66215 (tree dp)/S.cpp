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
template<typename T> inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
template<typename T> T gcd_iter(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
template<typename T> T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
template<typename T> T bigmod_iter(T b, T p, T m) { T r = 1; while(p > 0) { if(p & 1) r = (r * b) % m; p >>= 1; b = (b * b) % m; } return r; }
template<typename T> T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
template<typename T> T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
template<typename T> T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 105

const int SMALL = -(1 << 29);

int K;
int arr[SIZ];
vii tree[SIZ];
int save1[SIZ][SIZ];
int calc1[SIZ][SIZ];
int save2[SIZ][SIZ][SIZ];
int calc2[SIZ][SIZ][SIZ];

int recurRoot(int u, int k, int par);
int recurChild(int u, int k, int par, int p);

int recurRoot(int u, int k, int par = -1)
{
    if(k == 0) return 0;

    int& dp = save1[u][k];
    int& dpc = calc1[u][k];
    if(dpc == cas) return dp;

    dpc = cas;
    dp = arr[u] +  //take this node
         recurChild(u, k - 1, par, 0); //take k - 1 node from childs

    if(k == K) // if no this is root, select another node as root
    {
        loop(v, tree[u])
        if(*v != par)
            dp = max(dp, recurRoot(*v, k, u));
    }

    return dp;
}

int recurChild(int u, int k, int par, int p)
{
    if(k == 0) return 0;
    if(p == tree[u].size()) return SMALL;

    int& dp = save2[u][k][p];
    int& dpc = calc2[u][k][p];
    if(dpc == cas) return dp;

    dpc = cas;
    dp = recurChild(u, k, par, p + 1);

    int v = tree[u][p];
    if(v == par) return dp;

    REPE(i, 1, k)
    {
        dp = max(dp,
                 recurRoot(v, i, u) + //take i node from this child
                 recurChild(u, k - i, par, p + 1)); //move to other child to take rest of the nodes
    }

    return dp;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int n, u, v;
    while(sf2(n, K) == 2)
    {
        REP(i, 0, n)
        sf1(arr[i]);

        REP(i, 1, n)
        {
            sf2(u, v);
            tree[u].pb(v);
            tree[v].pb(u);
        }

        ++cas;
        int res = recurRoot(0, K);
        printf("%d\n", res);

        REPE(i, 0, n)
        tree[i].clear();
    }

    return 0;
}

/*
15 6
4 2 21 30 200 10 20 13 15 30 500 8 5 30 100
0 13
13 14
1 10
10 11
10 12
2 1
7 1
7 9
6 7
7 8
2 4
2 3
5 2
1 13
******
853
*/
