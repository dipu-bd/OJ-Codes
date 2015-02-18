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
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p>>1)); if(p&1) res*=n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
TEMPLATE T exgcd(T a,T b,T& x,T& y) { if(!b) { x=1; y=0; return a; } else { T g = exgcd(b, a%b, y, x); y -= (a/b)*x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

int n, m;
char inp[55][55];
bool mat[55][55];
int dis[55][55][4];
bool vis[55][55][4];

int DX[] = {0, 1, 0, 1};
int DY[] = {0, 0, 1, 1};

bool isenable(int x, int y)
{
    REP(i, 0, 4)
    {
        int p = x + DX[i];
        int q = y + DY[i];
        if(p > 0 && p <= n && q > 0 && q <= m)
        {
            if(inp[p][q] == '1') return false;
        }
    }
    return true;
}

int X[] = { -1, 0, 1, 0};
int Y[] = { 0, 1, 0, -1};

bool isvalid(int x, int y)
{
    return (x >= 0 && y >= 0 && x <= n && y <= m && mat[x][y]);
}

int getdir(char d)
{
    if(d == 'n') return 0;
    else if(d == 'e') return 1;
    else if(d == 's') return 2;
    else if(d == 'w') return 3;
}

void BFS(int ix, int iy, int id)
{
    clr(vis);
    queue<int> Q;
    Q.push(ix);
    Q.push(iy);
    Q.push(id);
    dis[ix][iy][id] = 0;
    vis[ix][iy][id] = 1;
    while(Q.size())
    {
        ix = Q.front(); Q.pop();
        iy = Q.front(); Q.pop();
        id = Q.front(); Q.pop();

        //turn left
        int nd = pmod(id - 1, 4);
        if(!vis[ix][iy][nd])
        {
            Q.push(ix);
            Q.push(iy);
            Q.push(nd);
            vis[ix][iy][nd] = 1;
            dis[ix][iy][nd] = dis[ix][iy][id] + 1;
        }

        //turn right
        nd = pmod(id + 1, 4);
        if(!vis[ix][iy][nd])
        {
            Q.push(ix);
            Q.push(iy);
            Q.push(nd);
            vis[ix][iy][nd] = 1;
            dis[ix][iy][nd] = dis[ix][iy][id] + 1;
        }

        //move forward
        REPE(i, 1, 3)
        {
            int x = ix + i * X[id];
            int y = iy + i * Y[id];
            if(!isvalid(x, y)) break;
            if(!vis[x][y][id])
            {
                Q.push(x);
                Q.push(y);
                Q.push(id);
                vis[x][y][id] = 1;
                dis[x][y][id] = dis[ix][iy][id] + 1;
            }
        }

    }
}


int main()
{
    char dir[30];
    int ix, iy, id, dx, dy;

    while(cin >> n >> m && n && m)
    {
        REPE(i, 1, n)
        REPE(j, 1, m)
        {
            scanf(" %c", &inp[i][j]);
        }

        REPE(i, 0, n)
        REPE(j, 0, m)
        {
            mat[i][j] = isenable(i, j);
        }

        scanf("%d %d %d %d %s", &ix, &iy, &dx, &dy, dir);

        id = getdir(dir[0]);
        BFS(ix, iy, id);

        bool v = false;
        int d = INT_MAX;
        REP(i, 0, 4)
        {
            if(vis[dx][dy][i])
            {
                v = true;
                d = min(d, dis[dx][dy][i]);
            }
        }
        if(!v) d = -1;

        printf("%d\n", d);
    }

    return 0;
}
