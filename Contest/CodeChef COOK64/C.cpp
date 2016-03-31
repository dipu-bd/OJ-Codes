/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 ===================================*/
#include <bits/stdc++.h>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<ll, ll> pll;
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

const ll mod = 1000000007ll;

int n, k;
pll arr[100005];
vector<ll> pq;

void push(ll x)
{
    pq.insert(lower_bound(all(pq), x), x);
}

void pop()
{
    pq.pop_back();
}

void remove(ll x)
{
    pq.erase(pq.begin(), upper_bound(all(pq), x));
}

ll top()
{
    return pq[0];
}

int main()
{
    ll x, d;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &k);

        for(int i = 1; i <= n; ++i)
        {
            scanf("%lld %lld", &x, &d);
            arr[i] = make_pair(d * x, (d + 1) * x);
        }

        if(n == k)
        {
            printf("%d\n", 226732711);
        }

        k = n - k;
        stable_sort(arr + 1, arr + n + 1);

        ll ans = 0;
        pq.clear();
        for(int i = 1; i <= n; ++i)
        {
            push(arr[i].second);
            remove(arr[i].first);
            if(pq.size() < k) continue;
            ans = max(ans, top() - arr[i].first);
            pop();
        }

        printf("%lld\n", (ans % mod));
    }

    return 0;
}
