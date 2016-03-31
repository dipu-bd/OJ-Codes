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

ll save[5003];
ll temp[5003];
int a, b, n, k;
ll mod = 1000000007;

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    cin >> n >> a >> b >> k;

    if(a > b) //reverse flow
    {
        a = n - a + 1;
        b = n - b + 1;
    }

    //for each step, calc the number of ways to reach floor [1] to [b-1]
    save[a] = 1;
    while(k--)
    {
        ll way = save[1];
        for(int i = 1, p = 2; i < b; ++i) //i is the lowest reach
        {
            //add number of ways to reach floor [i] from max reach floor
            while(p - i < b - p) //going down from floor [p] to [i]
            {
                way += save[p++];
            }
            //[i] can always be reached from lower levels.
            //so result = sum of ways upto max reach - ways to reach [i] itself
            temp[i] = way - save[i];
        }
        for(int i = 1; i < b; ++i)
        {
            save[i] = temp[i] % mod;
        }
    }

    //answer is sum of number of ways to reach floors [1] to [b-1]
    ll ans = 0;
    for(int i = 1; i < b; ++i)
    {
        ans += save[i];
    }

    cout << pmod(ans, mod) << endl;

    return 0;
}

/*
5000 2500 5000 5000

233993486
*/

