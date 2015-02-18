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
const int CHAR_INF = 0x7F;
const int INT_INF = 0x7F7F7F7F;
const long long LONG_INF = 0X7F7F7F7F7F7F7F7F;
TEMPLATE inline T sqr(T n) { return n * n; }
TEMPLATE inline T pmod(T n, T m) { return ((n % m) + m) % m; }
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
TEMPLATE T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 1003


int n, m;
int mat[SIZ][SIZ];
pii par[SIZ][SIZ];
int ans[100005];
vector<pii> col;

pii getpar(int i, int j)
{
    if(mp(i, j) == par[i][j]) return par[i][j];
    return par[i][j] = getpar(par[i][j]);
}

void connect(int i, int j, int i2, int j2)
{
    pii pu = getpar(i, j);
    pii pv = getpar(i2, j2);
    if(pu == pv) return;
    par[pu.fr][pu.sc] = pv;
}

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

void dfs(int i, int j)
{
    vis[i][j] = cas;
    REP(k, 0, 4)
    {
        x = i + X[k];
        y = j + Y[k];
        if(x >= 0 && x < n && y >= 0 && y < m  &&
                mat[x][y] >= mat[i][j] && vis[i][j] != cas)
        {
            connect(x, y, i, j);
            dfs(x, y);
        }
    }
}

bool comp(const pii& a, const pii& b)
{
    return a.fr < b.fr;
}

int main()
{
    int x;

    sf1(test);
    while(test--)
    {
        ++cas;
        num.clear();

        sf2(n, m);

        REP(i, 0, n)
        REP(j, 0, m)
        {
            sf1(mat[i][j]);
        }

        sf1(q);
        int x;
        col.clear();
        REP(i, 0, q)
        {
            sf1(x);
            col.pb(mp(x, i));
        }

        ssort(col);

        int last = 0;
        rloop(it, col)
        {
            int cnt = 0;
            pii& p = *it;
            REP(i, 0, n)
            REP(i, 0, m)
            if(mat[i][j] >= p.fr && vis[i][j])
            {
                dfs(i, j);
                ++cnt;
            }
            last = cnt;
        }
    }

    return 0;
}
