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

struct point
{
    int x;
    int y;
    int d;
};

#define SIZ 105
int m, n, v;
char board[SIZ][SIZ];
int dis[SIZ][SIZ];
bool vis[SIZ][SIZ];


int X[] = { -2, -1, 1, 2, 2, -2,  1, -1 };
int Y[] = { -1, -2, 2, 1, -1, 1, -2,  2 };

bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < m && j < n
           && !vis[i][j] && !board[i][j];
}

vii BFS(int bx, int by, int ex, int ey, int id = -1)
{
    vii dir;
    point p;
    point m;
    queue<point> q;

    clr(vis);
    mem(dis, 0x7F);
    dis[bx][by] = 0;
    p.x = bx;
    p.y = by;
    p.d = id;
    q.push(p);

    while(q.size())
    {
        p = q.front();
        q.pop();

        if(p.x == ex && p.y == ey)
        {
            dir.pb(p.d);
            continue;
        }

        int ds = dis[p.x][p.y];

        REP(i, 0, 8)
        {
            if(i == p.d) continue;

            m.d = i;
            m.x = p.x + X[i];
            m.y = p.y + Y[i];

            if(valid(m.x, m.y))
            {
                q.push(m);
                vis[m.x][m.y] = 1;
                dis[m.x][m.y] = min(dis[m.x][m.y], (i < 4 ? ds : ds + 1));
            }
        }
    }

    return dir;
}

int ans;
int total;
pii star[10];
bool masked[10];

void backtrack(int x = 0, int y = 0, int d = -1)
{

    bool allv = true;
    REP(i, 0, v)
    {
        if(masked[i]) continue;
        allv = false;

        vii dir = BFS(x, y, star[i].fr, star[i].sc, d);
        int ds = dis[star[i].fr][star[i].sc];

        if(dir.size())
        printf("%d %d [%d]\n", x, y, dir[0]);

        total += ds;
        if(d == -1) ++total;
        masked[i] = 1;

        loop(x, dir)
        backtrack(star[i].fr, star[i].sc, *x);

        total -= ds;
        if(d == -1) --total;
        masked[i] = 0;
    }

    if(allv)
    {
        if(ans > total) ans = total;
        return;
    }
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int d, x, y;

    sf1(test);
    while(test--)
    {
        sf3(m, n, d);

        clr(board);
        while(d--)
        {
            sf2(x, y);
            board[x][y] = 1;
        }

        sf1(v);
        REP(i, 0, v)
        {
            sf2(x, y);
            star[i].fr = x;
            star[i].sc = y;
        }

        if(v == 0)
            ans = 0;
        else
        {
            total = 0;
            ans = INT_MAX;
            backtrack();
        }

        printf("Case %d: ", cas++);
        if(ans != INT_MAX) printf("%d\n", ans);
        else puts("Impossible");
    }

    return 0;
}
