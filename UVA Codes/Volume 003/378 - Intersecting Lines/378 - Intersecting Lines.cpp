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
//#include <assert.h>
//#include <time.h>
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
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
#define debug1(a) cout << a << endl
#define debug2(a,b) cout << a << " " << b << endl
#define debug3(a,b,c) cout << a << " " << b << " " << c << endl
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define allof(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
const double EPS = 1E-10;
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
template<typename T> T gcd_iter(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
template<typename T> T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
template<typename T> T bigmod_iter(T b, T p, T m) { T r = 1; while(p > 0) { if(p & 1) r = (r * b) % m; p >>= 1; b = (b * b) % m; } return r; }
template<typename T> T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
template<typename T> T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
template<typename T> T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

int main()
{
    ll x1, y1, x2, y2;
    ll x3, y3, x4, y4;
    ll a1, a2, b1, b2, c1, c2;

    sf1(test);
    puts("INTERSECTING LINES OUTPUT");
    while(test--)
    {
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);

        a1 = y1 - y2;
        b1 = x2 - x1;
        c1 = x1 * y2 - y1 * x2;

        a2 = y3 - y4;
        b2 = x4 - x3;
        c2 = x3 * y4 - y3 * x4;

        ll del = (a1 * b2 - a2 * b1);
        if(del == 0)
        {
            if(a1 * x3 + b1 * y3 == -c1 && a1 * x4 + b1 * y4 == -c1)
                puts("LINE");
            else
                puts("NONE");
        }
        else
        {
            printf("POINT ");

            if(b1 * c2 == b2 * c1)
                printf("0.00 ");
            else
            {
                double x = (double)(b1 * c2 - b2 * c1) / (double)del;
                ll xx = (ll)round(x * 100 + 1e-8);
                ll prx = xx / 100, qrx = xx % 100;
                printf("%lld.%.2lld ", prx, qrx);
            }

            if(a2 * c1 == a1 * c2)
                printf("0.00\n");
            else
            {
                double y = (double)(a2 * c1 - a1 * c2) / (double)del;
                ll yy = (ll)round(y * 100 + 1e-8);
                ll pry = yy / 100, qry = yy % 100;
                printf("%lld.%.2lld\n", pry, qry);
            }
        }
    }
    puts("END OF OUTPUT");

    return 0;
}

/*
1
1 0 1 1 2 0 2 1
*/
