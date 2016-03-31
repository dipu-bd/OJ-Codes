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
ll power(ll n, ll p) { if(!p) return 1; else { ll res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
ll exgcd(ll a, ll b, ll& x, ll& y) { if(!b) { x = 1; y = 0; return a; } else { ll g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
ll modinv(ll a, ll m) { ll x, y; exgcd(a, m, x, y); return pmod(x, m); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

ll mod = 1000000007;
ll phimod = 1000000006;
map<int, int> prime;


ll bigmod(ll n, ll p, ll m)
{
    if(p <= 0) return 1;
    ll r = bigmod(n, p >> 1, m);
    r = (r * r) % m;
    if(p & 1)  r = (r * n) % m;
    return r;
}

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int m,  p;
    ll sig0, half, n, ans;

    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &p);
        prime[p]++;
    }

    bool odd = 1;
    sig0 = half = 1;
    loop(it, prime)
    {
        n = (n * bigmod(it->first, it->second, mod)) % mod;
        half = (half * bigmod(it->first, it->second >> 1, mod)) % mod;

        if(odd && (it->second & 1))
        {
            odd = 0;
            sig0 = (sig0 * ((1 + it->second) >> 1)) % phimod;
        }
        else
        {
            sig0 = (sig0 * (1 + it->second)) % phimod;
        }
    }

    if(odd)
    {
        ans = bigmod(half, sig0, mod);
    }
    else
    {
        ans = bigmod(n, sig0, mod);
    }

    cout << ans << endl;

    return 0;
}


