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

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

int n, m;
int dis[210][210];
int jdis[210][210];
bool vis[210][210];
char mat[210][210];

void BFS_Fire()
{
    clr(vis);
    queue<int> q;
    REP(i, 0, n)
    REP(j, 0, m)
    {
        if(mat[i][j] != 'F') continue;
        q.push(i);
        q.push(j);
        vis[i][j] = 1;
        dis[i][j] = 0;
    }

    while(q.size())
    {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();

        int d = dis[x][y] + 1;
        REP(i, 0, 4)
        {
            int a = x + X[i];
            int b = y + Y[i];
            if(a >= 0 && b >= 0 && a < n && b < m && !vis[a][b] && mat[a][b] != '#')
            {
                q.push(a);
                q.push(b);
                vis[a][b] = 1;
                dis[a][b] = d;
            }
        }
    }
}

int BFS_Jane(int x, int y)
{
    clr(vis);
    queue<int> q;
    q.push(x);
    q.push(y);
    vis[x][y] = 1;
    jdis[x][y] = 0;

    while(q.size())
    {
        x = q.front(); q.pop();
        y = q.front(); q.pop();

        int d = jdis[x][y] + 1;
        REP(i, 0, 4)
        {
            int a = x + X[i];
            int b = y + Y[i];
            if(a < 0 || b < 0 || a >= n || b >= m) return d;
            if(!vis[a][b] && mat[a][b] != '#' && d < dis[a][b])
            {
                q.push(a);
                q.push(b);
                vis[a][b] = 1;
                jdis[a][b] = d;
            }
        }
    }

    return -1;
}

int solve()
{
    BFS_Fire();

    int jx, jy;
    bool found = 0;
    REP(i, 0, n)
    {
        REP(j, 0, m)
        if(mat[i][j] == 'J')
        {
            jx = i;
            jy = j;
            found = true;
        }
        if(found) break;
    }

    clr(vis);
    return BFS_Jane(jx, jy);
}

int main()
{
    sf1(test);
    while(test--)
    {
        sf2(n, m);
        REP(i, 0, n)
        scanf(" %s", mat[i]);

        int res = solve();
        printf("Case %d: ", cas++);
        if(res == -1) puts("IMPOSSIBLE");
        else printf("%d\n", res);
    }

    return 0;
}
