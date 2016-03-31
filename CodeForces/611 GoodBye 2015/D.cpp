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

const int SIZ = 5005;
const ll mod = (ll)(1e9 + 7.7);

int n;
char num[SIZ];
ll mat[SIZ][SIZ];
int nxt[SIZ][SIZ];

inline int compare(int a, int b, int c)
{
    if((b - a) == (c - b + 1))
    {
        int x = nxt[a][b];
        if(a + x < b)
            return num[a + x] < num[b + x];
    }
    return (b - a) < (c - b + 1);
}

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    scanf("%d %s", &n, num + 1);

    for(int j = n; j >= 1; --j)
    {
        for(int i = j; i >= 1; --i)
        {
            nxt[i][j] = 0;
            if(num[i] == num[j])
                nxt[i][j] = nxt[i + 1][j + 1] + 1;
        }
    }

    for(int q = 1; q <= n; ++q)
    {
        mat[1][q] = 1;
        for(int p = 2; p <= q; ++p)
        {
            mat[p][q] = mat[p - 1][q];
            if(num[p] == '0') continue;

            int r = max(1, 2 * p - q) - 1;
            if(r >= p) continue;

            mat[p][q] = (mat[p - 1][p - 1] - mat[r][p - 1] + mat[p][q]) % mod;
            if(r > 0 && num[r] != '0' && compare(r, p, q))
            {
                mat[p][q] = (mat[r][p - 1] - mat[r - 1][p - 1] + mat[p][q]) % mod;
            }
        }
    }

    cout << pmod(mat[n][n], mod) << endl;

    return 0;
}


