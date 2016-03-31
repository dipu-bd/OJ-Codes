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

#define SIZ 1000006

int n;
int arr[SIZ];
int pos[SIZ];
int rev[SIZ];
bool vis[SIZ];
vector<int> cycle;
map<int, vector<int>> evens;

void findcycle(int p)
{
    cycle.clear();
    while(!vis[p])
    {
        vis[p] = true;
        cycle.push_back(p);
        p = arr[p];
    }
}

void alternate(const vector<int>& q)
{
    int t = q.size();
    for(int i = 0; i < t; ++i)
    {
        pos[q[i]] = q[(i + (t + 1) / 2) % t];
    }
}

void merge(const vector<int>& a, const vector<int>& b)
{
    int t = a.size();
    for(int i = 0; i < t; ++i)
    {
        pos[a[i]] = b[i];
        pos[b[i]] = a[(i + 1) % t];
    }
}

bool check()
{
    for(int i = 1; i <= n; ++i)
    {
        if(!pos[i]) return true;
        rev[i] = pos[pos[i]];
    }
    for(int i = 1; i <= n; ++i)
    {
        if(rev[i] != arr[i])
            return true;
    }
    return false;
}

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            findcycle(i);

            int t = cycle.size();

            if(t & 1)
            {
                alternate(cycle);
            }
            else
            {
                if(evens.count(t))
                {
                    merge(evens[t], cycle);
                    evens.erase(t);
                }
                else
                {
                    evens[t] = cycle;
                }
            }
        }
    }

    if(check())
    {
        puts("-1");
    }
    else
    {
        for(int i = 1; i <= n; ++i)
        {
            printf("%d ", pos[i]);
        }
    }

    return 0;
}


/*
100
94 22 24 99 58 97 20 29 67 30 38 64 77 50 15 44 92 88 39 42 25 70 2 76 84 6 37 49 17 71 31 19 26 79 10 35 65 63 32 95 5 8 52 27 83 18 53 93 13 81 48 68 54 82 34 60 87 23 16 86 55 40 61 45 28 7 74 41 14 91 3 72 33 11 98 89 90 69 78 36 80 59 56 21 43 1 75 46 47 12 96 73 57 51 4 85 9 100 66 62
*/
