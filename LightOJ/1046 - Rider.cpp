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
#define REPES(i, a, n, s) for(int i = a; i <= n; i += s)
#define RREPES(i, a, n, s) for(int i = a; i >= n; i -= s)
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
const double EPS = 1E-10;
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
double combi(ll n, ll k) { if(2 * k > n) return combi(n, n - k); double res = 1.0; REP(i, 0, k) res *= (double)(n - i) / (i + 1); return res; }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

int m, n;
vpii knight;
char mat[15][15];
bool vis[15][15];
int dist[15][15];

int X[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int Y[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

int BFS(int x, int y)
{
    clr(vis);
    queue<int> q;
    q.push(x);
    q.push(y);
    dist[x][y] = 0;
    vis[x][y] = true;
    while(q.size())
    {
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();

        int d = dist[x][y] + 1;
        REP(i, 0, 8)
        {
            int a = x + X[i];
            int b = y + Y[i];
            if(a >= 0 && b >= 0 && a < m && b < n && !vis[a][b])
            {
                q.push(a);
                q.push(b);
                dist[a][b] = d;
                vis[a][b] = true;
            }
        }
    }
}

int getceil(int a, int b)
{
    if(!a) return 0;
    return (a / b) + (a % b > 0);
}

int getmove(int x, int y)
{
    BFS(x, y);
    int mov = 0;
    loop(k, knight)
    {
        if(!vis[k->fr][k->sc]) return INT_MAX;
        mov += getceil(dist[k->fr][k->sc], mat[k->fr][k->sc]);
    }
    return mov;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    sf1(test);
    while(test--)
    {
        sf2(m, n);

        knight.clear();
        REP(i, 0, m)
        REP(j, 0, n)
        {
            scanf(" %c", &mat[i][j]);
            if(isdigit(mat[i][j]))
            {
                knight.pb(mp(i, j));
                mat[i][j] -= '0';
            }
        }

        int mov = INT_MAX;
        REP(i, 0, m)
        REP(j, 0, n)
        mov = min(mov, getmove(i, j));

        if(mov == INT_MAX) mov = -1;
        printf("Case %d: %d\n", cas++, mov);
    }

    return 0;
}

