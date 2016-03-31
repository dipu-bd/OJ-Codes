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

int n, k;
int arr[600005];
int dan[600005];
int last[1000006];
set<int> took;

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);

    for(int i = n; i >= 1; --i)
    {
        dan[i] = last[arr[i]] > i ? last[arr[i]] : n + 1;
        last[arr[i]] = i;
    }

    int ansl = 1, ansr = k;
    for(int l = 1, r = 1; r <= n; ++r)
    {
        took.insert(arr[r]);

        while(took.size() > k)
        {
            if(dan[l] > r)
                took.erase(arr[l]);
            ++l;
        }

        if(ansr - ansl < r - l)
        {
            ansl = l;
            ansr = r;
        }
    }

    printf("%d %d\n", ansl, ansr);

    return 0;
}


