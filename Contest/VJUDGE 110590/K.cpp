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

#define MAX 100006
int arr[MAX];
map<int,pii> pos;
int tree[MAX << 2];

void build(int nod, int b, int e)
{
    if(b == e)
    {
        tree[nod] = 1;
        return;
    }

    int mid = (b + e) >> 1;
    int left = nod << 1;
    int right = (nod << 1) + 1;

    pii& p = pos[arr[mid]];
    tree[nod] = min(p.second, e) - max(p.first, b) + 1;

    build(left, b, mid);
    build(right, mid + 1, e);

    tree[nod] = max(tree[nod], tree[left]);
    tree[nod] = max(tree[nod], tree[right]);
}

int query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j)
    {
        return tree[nod];
    }

    int mid = (b + e) >> 1;
    int left = nod << 1;
    int right = (nod << 1) + 1;

    pii& p = pos[arr[mid]];
    int res = min(p.second, min(e, j)) - max(p.first, max(i, b)) + 1;

    if(i <= mid) res = max(res, query(left, b, mid, i, j));
    if(j > mid) res = max(res, query(right, mid + 1, e, i, j));

    return res;
}

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int n, q, x, y;
    arr[0] = INT_MIN;
    while(scanf("%d %d", &n, &q) == 2, n)
    {
        pos.clear();
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);

            pii& p = pos[arr[i]];
            if(arr[i] == arr[i - 1])
                p.second = i;
            else
                p.first = i;
        }

        build(1, 1, n);

        for(int i =  1; i <= q; ++i)
        {
            scanf("%d %d", &x, &y);
            int res = query(1, 1, n, x, y);
            printf("%d\n", res);
        }
    }

    return 0;
}


