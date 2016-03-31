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

int arr[100005];

int main()
{
    freopen("the_price_is_correct.txt", "r", stdin);
    freopen("the_price_is_correct_output.txt", "w", stdout);

    ll p;
    int n;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %lld", &n, &p);

        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
        }

        ll way = 0;
        ll sum = 0;
        int a = 1, b = 1;
        while(a <= n)
        {
            if(b <= n && sum + arr[b] <= p)
            {
                sum += arr[b];
                ++b;
                way += b - a;
            }
            else
            {
                sum -= arr[a];
                ++a;
            }
        }

        printf("Case #%d: %lld\n", cas++, way);
    }

    return 0;
}


