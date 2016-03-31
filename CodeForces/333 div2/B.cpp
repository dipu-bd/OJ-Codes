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

int n, arr[100005];

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif


    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", arr + i);
    }

    int ans = 1;
    int l = 1, x = 1, y = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(arr[i] < arr[x])
        {
            if(arr[x] - arr[i] >= 2)
            {
                l = x = y = i;
            }
            else if(arr[y] - arr[i] >= 2)
            {
                l = y + 1;
                y = max(l, x);
                x = i;
            }
            else
            {
                x = i;
            }
        }
        else if(arr[i] > arr[y])
        {
            if(arr[i] - arr[y] >= 2)
            {
                l = x = y = i;
            }
            else if(arr[i] - arr[x] >= 2)
            {
                l = x + 1;
                x = y;
                y = i;
            }
            else
            {
                y = i;
            }
        }
        else
        {
            if(arr[i] == arr[x])
            {
                x = i;
            }
            if(arr[i] == arr[y])
            {
                y = i;
            }
        }
        ans = max(ans, i - l + 1);
    }

    cout << ans << endl;

    return 0;
}
