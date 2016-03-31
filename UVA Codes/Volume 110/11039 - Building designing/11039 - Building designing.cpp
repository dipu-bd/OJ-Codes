/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
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

vector<int> col[2];

int main()
{
    int n, x;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        
        col[0].clear();
        col[1].clear();
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &x);
            if(x < 0) 
            {
                col[0].push_back(-x);
            }
            else 
            {
                col[1].push_back(x);
            }
        }
        
        sort(all(col[0]));
        sort(all(col[1]));
        
        int sz[2];
        sz[0] = col[0].size() - 1;
        sz[1] = col[1].size() - 1;
        int p = col[0][sz[0]], t = 1, d = 1;
        if(p < col[1][sz[1]])
        {
            p = col[1][sz[1]];
            d = 0;
        }
        while(sz[0] >= 0 && sz[1] >= 0)
        {
            while(sz[d] >= 0 && col[d][sz[d]] >= p) --sz[d];
            if(sz[d] >= 0)
            {
                p = col[d][sz[d]]; 
                d = 1 - d;
                ++t;
            }
        }
        
        printf("%d\n", t);
    }
    
    return 0;
}
