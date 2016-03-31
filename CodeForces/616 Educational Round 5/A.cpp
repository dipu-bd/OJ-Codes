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

char num1[1000006];
char num2[1000006];

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    scanf(" %s %s", num1, num2);

    int is = 0, js = 0;
    int ilen = strlen(num1);
    int jlen = strlen(num2);

    while(is + 1 < ilen && num1[is] == '0') ++is;
    while(js + 1 < jlen && num2[js] == '0') ++js;

    if(ilen - is == jlen - js)
    {
        bool eq = 1;
        for(int i = is, j = js; i < ilen; ++i, ++j)
        {
            if(num1[i] != num2[j])
            {
                eq = 0;
                putchar((num1[i] < num2[i]) ? '<' : '>');
                break;
            }
        }
        if(eq) putchar('=');
    }
    else
    {
        putchar((ilen - is < jlen - js) ? '<' : '>');
    }

    return 0;
}
