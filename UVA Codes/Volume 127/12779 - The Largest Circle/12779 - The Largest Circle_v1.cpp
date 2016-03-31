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

struct POINT
{
    ll x, y;
};

inline ll sqdist(POINT a, POINT b)
{
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

inline ll getarea(POINT a, POINT b, POINT c, POINT d)
{
    return (a.x * b.y + b.x * c.y + c.x * d.y + d.x * a.y) -
           (a.x * d.y + b.x * a.y + c.x * b.y + d.x * c.y);
}

int main()
{
    POINT a, b, c, d;
    while(scanf("%lld %lld %lld %lld %lld %lld %lld %lld",
                &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y) == 8)
    {
        if(!(a.x || b.x || c.x || d.x || a.y || b.y || c.y || d.y)) break;

        ll area = getarea(a, b, c, d);
        ll ab = sqdist(a, b);
        ll bc = sqdist(b, c);
        ll up = area * area;
        ll down = 16 * max(ab, bc);

        if(down == 0)
        {
            puts("-1");
        }
        else
        {
            ll g = gcd(up, down);
            up /= g;
            down /= g;
            printf("(%lld/%lld)*pi\n", up, down);
        }
    }

    return 0;
}
