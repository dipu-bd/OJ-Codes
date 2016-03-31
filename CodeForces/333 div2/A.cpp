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

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ll n, bx, by, x, m;

    cin >> n >> bx;

    ll a = 0, p = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> x;
        a = a * bx + x;
        p += pow(bx, n - i - 1) * x;
    }

    cin >> m >> by;
    ll b = 0, q = 0;
    for(int i = 0; i < m; ++i)
    {
        cin >> x;
        b = b * by + x;
        q += pow(by, m - i - 1) * x;
    }

    cerr << a << " " << b << endl;
    cerr << p << " " << q << endl;

    if(a == b)
    {
        puts("=");
    }
    else if(a < b)
    {
        puts("<");
    }
    else
    {
        puts(">");
    }
    if(p == q)
    {
        puts("=");
    }
    else if(p < q)
    {
        puts("<");
    }
    else
    {
        puts(">");
    }

    return 0;
}

/*
9 39
10 20 16 36 30 29 28 9 8
9 38
12 36 10 22 6 3 19 12 34
*/
