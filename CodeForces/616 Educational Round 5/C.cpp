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

int n, m, cnum;
int comp[1010][1010];
char mat[1010][1010];
int freq[1000006];

void dfs(int i, int j)
{
    if(i < 0 || j < 0 || i >= n || j >= m || comp[i][j] || mat[i][j] == '*')
        return;

    comp[i][j] = cnum;
    freq[cnum]++;

    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n; ++i)
        scanf(" %s", mat[i]);

    cnum = 1;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(!comp[i][j] && mat[i][j] == '.')
            { dfs(i, j); cnum++; }

    set<int> tt;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(mat[i][j] != '.')
            {
                tt.clear();
                int ans = 1;
                if(i > 0 && !tt.count(comp[i - 1][j]))
                {
                    ans += freq[comp[i - 1][j]];
                    tt.insert(comp[i - 1][j]);
                }
                if(i + 1 < n && !tt.count(comp[i + 1][j]))
                {
                    ans += freq[comp[i + 1][j]];
                    tt.insert(comp[i + 1][j]);
                }
                if(j > 0 && !tt.count(comp[i][j - 1]))
                {
                    ans += freq[comp[i][j - 1]];
                    tt.insert(comp[i][j - 1]);
                }
                if(j + 1 < m && !tt.count(comp[i][j + 1]))
                {
                    ans += freq[comp[i][j + 1]];
                    tt.insert(comp[i][j + 1]);
                }
                mat[i][j] = '0' + (ans % 10);
            }

    for(int i = 0; i < n; ++i)
        puts(mat[i]);

    return 0;
}


