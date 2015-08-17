/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
//#include <bits/stdc++.h>
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
//cpp headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
//#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<int> vii;
typedef vector<pii> vpii;
typedef map<int, int> mpii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//io
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
#define TEMPLATE template<typename T>
//variables and functions
const double EPS = 1E-10;
const double PI = 2.0 * acos(0.0);
TEMPLATE inline T sqr(T n) { return n * n; }
TEMPLATE inline T pmod(T n, T m) { return ((n % m) + m) % m; }
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, ll p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
TEMPLATE T bigmod(T n, ll p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
TEMPLATE T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;
//const int oo = 1 << 30;
//const int mod = 1000000007;

#define SIZ 200010

int arr[SIZ];
int tree[SIZ << 2];

void build(int nod, int b, int e)
{
    if(b == e)
    {
        tree[nod] = arr[b];
        return;
    }

    int m = (b + e) >> 1;
    int left = nod << 1;
    int right = left + 1;

    build(left, b, m);
    build(right, m + 1, e);
    tree[nod] = tree[left]  + tree[right];
}

int query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j)
    {
        return tree[nod];
    }

    int m = (b + e) >> 1;
    int left = nod << 1;
    int right = left + 1;

    int res = 0;
    if(i <= m) res += query(left, b, m, i, j);
    if(j > m) res += query(right, m + 1, e, i, j);
    return res;
}

void update(int nod, int b, int e, int x, int v)
{
    if(b == e)
    {
        tree[nod] = v;
        return;
    }

    int m = (b + e) >> 1;
    int left = nod << 1;
    int right = left + 1;

    if(x <= m) update(left, b, m, x, v);
    else update(right, m + 1, e, x, v);
    tree[nod] = tree[left]  + tree[right];
}

int main()
{
    int n;
    int x, y;
    char com[20];

    while(sf1(n) == 1 && n)
    {
        REPE(i, 1, n)
        {
            sf1(arr[i]);
        }

        build(1, 1, n);

        if(cas > 1) putchar('\n');
        printf("Case %d:\n", cas++);
        while(scanf(" %s", com) == 1 && strcmp(com, "END"))
        {
            sf2(x, y);
            if(com[0] == 'S')
            {
                update(1, 1, n, x, y);
            }
            else if(com[0] == 'M')
            {
                printf("%d\n", query(1, 1, n, x, y));
            }
        }

    }

    return 0;
}
