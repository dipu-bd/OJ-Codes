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
template<typename T> T bigmod(T n,  long long p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
template<typename T> T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
template<typename T> T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
/*------------------------------------------------------------------------------------*/
//typedefs
typedef long long ll;
typedef pair<ll, ll> pii;

int test, cas = 1;

int h, w;
char inp[505][505];
int ver[505][505];
int hor[505][505];

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d", &h, &w);
    for(int i = 1; i <= h; ++i)
    {
        scanf(" %s", inp[i] + 1);
    }

    for(int i = 1; i <= h; ++i)
    {
        for(int j = 1; j <= w; ++j)
        {
            if(inp[i][j] == '.')
            {
                if(inp[i - 1][j] == '.')
                    ver[i][j]++;
                if(inp[i][j - 1] == '.')
                    hor[i][j]++;
            }
            ver[i][j] += ver[i - 1][j];
            hor[i][j] += hor[i][j - 1];
        }
    }

    int q, r1, r2, c1, c2;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        int ans = 0;
        for(int i = r1; i <= r2; ++i)
        {
            ans += hor[i][c2] - hor[i][c1];
        }
        for(int i = c1; i <= c2; ++i)
        {
            ans += ver[r2][i] - ver[r1][i];
        }

        printf("%d\n", ans);
    }

    return 0;
}


