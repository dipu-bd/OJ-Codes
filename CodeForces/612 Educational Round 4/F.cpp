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

int n, s;
int arr[2016];
int mat[2016][2016];
int cost[2016], from[2016];
map<int, vector<int>> mpos;

int choosebest(int s, vector<int>& eqs)
{
    int mcost = INT_MAX, mv = -1;
    loop(i, eqs)
    {
        int u = *i;
        int loss = cost[s] + mat[s][u];

        for(int j = 0; j < eqs[j].size(); ++j)
        {
            int v = eqs[j], w = eqs[j + 1];
            if(v == u) continue;

        }
    }
}

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &s);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
        mpos[arr[i]].push_back(i);
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            mat[i][j] = 0;
            if(abs(arr[i] - arr[j]) <= 1)
            {
                int t = abs(i - j);
                mat[i][j] = min(t, n - t);

            }
        }
    }

    int p = s, cost = 0;
    loop(it, mpos)
    {
        p = choosebest(p, *it);
    }

    printf("%d\n", cost);

    return 0;
}


