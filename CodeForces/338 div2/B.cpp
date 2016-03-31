/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 ===================================*/
#include <bits/stdc++.h>
using namespace std;
//useful definitions
#define gcd(a,b) __gcd(a,b)
#define mem(a,b) memset(a, b, sizeof(a))
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
template<typename T> inline T sqr(T n) { return n * n; }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> T power(T n, long long p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
template<typename T> T bigmod(T n, long long p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
template<typename T> T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
template<typename T> T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
/*------------------------------------------------------------------------------------*/
//typedefs
typedef long long ll;
typedef pair<ll, ll> pii;

int test, cas = 1;

#define SIZ 100005

int n, m;
bool vis[SIZ];
pii data[SIZ];
ll number[SIZ];
vector<int> graph[SIZ];

ll recur(int u, int t)
{
    if(vis[u])
    {
        return number[data[u].first] * (data[u].second + t);
    }

    vis[u] = 1;
    ll dp = t * number[u];
    data[u] = make_pair(u, 0);

    loop(it, graph[u])
    {
        ll r = recur(*it, t + 1);
        if(r > dp)
        {
            dp = r;
            data[u] = data[*it];
            data[u].second++;
        }
    }

    return dp;
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
        number[u]++;
        number[v]++;
        if(u > v) swap(u, v);
        graph[u].push_back(v);
    }

    ll dp = 0;
    for(int i = 1; i <= n; ++i)
    {
        dp = max(dp, recur(i, 1));
    }

    cout << dp << endl;

    return 0;
}


