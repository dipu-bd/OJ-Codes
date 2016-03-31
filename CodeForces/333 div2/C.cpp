/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 ===================================*/
#include <bits/stdc++.h>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define all(v) v.begin(), v.end()
#define mem(a,b) memset(a, b, sizeof(a))
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
template<typename T> inline T sqr(T n) { return n * n; }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> T power(T n, ll p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
template<typename T> T bigmod(T n, ll p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
template<typename T> T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
template<typename T> T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

int n, m;
bool mat[500][500];
int dis[500];
bool vis[500];

int train()
{
    queue<int> qu;
    qu.push(1);
    dis[1] = 0;
    vis[1] = 1;
    while(qu.size())
    {
        int u = qu.front();
        qu.pop();

        if(u == n) return dis[u];

        //first move train, then bus
        for(int v = 1; v <= n; ++v)
        {
            if(mat[u][v] && !vis[v]) //b
            {
                qu.push(v);
                vis[v] = 1;
                dis[v] = dis[u] + 1;
            }
        }
    }
    return -1;
}

int bus()
{
    queue<int> qu;
    qu.push(1);
    dis[1] = 0;
    vis[1] = 1;
    while(qu.size())
    {
        int u = qu.front();
        qu.pop();

        if(u == n) return dis[u];

        //first move train, then bus
        for(int v = 1; v <= n; ++v)
        {
            if(!mat[u][v] && !vis[v]) //b
            {
                qu.push(v);
                vis[v] = 1;
                dis[v] = dis[u] + 1;
            }
        }
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int u, v;

    scanf("%d %d", &n, &m);
    while(m--)
    {
        scanf("%d %d", &u, &v);
        mat[u][v] = mat[v][u] = 1;
    }

    if(mat[1][n]) //has train route
    {
        printf("%d\n", bus()); // get bus route
    }
    else //has bus route
    {
        printf("%d\n", train()); // get train route
    }

    return 0;
}

