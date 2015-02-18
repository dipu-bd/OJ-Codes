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

int test, cas = 1;

/* please don't hack me!!! */

int n;
string name[110];
bool graph[250][250];
int indeg[250];
char vis[250];
vii topver;

bool dfs1(int u)
{
    if(vis[u] == 1) return true;
    vis[u] = 1;
    REPE(v, 'a', 'z')
    if(graph[u][v])
        if(dfs1(v)) return true;
    vis[u] = 2;
    return false;
}

bool hasloop()
{
    REPE(i, 'a', 'z')
    {
        if(vis[i] == 2) continue;
        if(dfs1(i)) return true;
    }
    return false;
}

void topsort()
{
    clr(vis);
    while(topver.size() <= 'z' - 'a' )
    {
        REPE(u, 'a', 'z')
        {
            if(!vis[u] && !indeg[u])
            {
                REPE(v, 'a', 'z')
                if(graph[u][v])
                    if(indeg[v]) --indeg[v];
                vis[u] = 1;
                topver.pb(u);
                break;
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    cin >> n;
    REP(i, 0, n)
    cin >> name[i];

    bool pos = true;
    REP(i, 0, n)
    {
        int j = i + 1;
        if(j == n) break;
        bool match = true;
        REP(k, 0, min(name[i].size(), name[j].size()))
        {
            if(name[i][k] != name[j][k])
            {
                bool& v = graph[name[i][k]][name[j][k]];
                if(!v)
                {
                    v = true;
                    indeg[name[j][k]]++;
                }
                match = false;
                break;
            }
        }
        if(match && name[i].size() > name[j].size())
            pos = false;
        if(!pos) break;
    }

    if(hasloop() || !pos)
    {
        puts("Impossible");
        return 0;
    }

    topsort();
    loop(it, topver)
    {
        putchar((char)*it);
    }
    putchar('\n');

    return 0;
}
