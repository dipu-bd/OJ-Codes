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

int n, k, x, y, p;
vector<pii> point;
vector<pii> ans;

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    cin >> n >> k;

    for(int i = 0; i < n; ++i)
    {
        scanf("%d %d", &x, &y);
        if(x > y) swap(x, y);
        point.push_back(make_pair(x, 0));
        point.push_back(make_pair(y, 1));
    }

    stable_sort(all(point));

    p = 0;
    loop(it, point)
    {
        pii& t = *it;
        if(t.second == 0)
        {
            ++p;
            if(p == k)
            {
                x = t.first;
            }
            if(p >= k)
            {
                y = t.first;
            }
        }
        else
        {
            if(p >= k)
            {
                y = t.first;
            }
            if(p == k)
            {
                ans.push_back(make_pair(x, y));
            }
            --p;
        }
    }

    printf("%d\n", ans.size());
    loop(it, ans)
    {
        printf("%d %d\n", it->first, it->second);
    }

    return 0;
}

