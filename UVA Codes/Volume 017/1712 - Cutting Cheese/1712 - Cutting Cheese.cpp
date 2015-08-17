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

struct Hole
{
    double r;
    double x;
    double y;
    double z;
    double vol;

    double setVol()
    {
        vol = 4.0 * PI * r * r * r / 3.0;
    }

    bool intersect(double k)
    {
        return fabs(z - k) < r;
    }

    double volCap(double k)
    {
        double h = r - fabs(z - k);
        double vcap = PI * sqr(h) * (3 * r - h) / 3.0;
        if(k > z) return vol - vcap;
        return vcap;
    }
};

int n, s;
Hole holes[10010];
double total, target;
const double full = 1e15;

bool compare(const Hole& h, const double& k)
{
    return (h.z - h.r) < k;
}

double getVolTo(double k, double pVol)
{
    double vol = 1e10 * k - pVol;
    for(int i = 0; i < n; ++i)
    {
        if(holes[i].intersect(k))
        {
            vol -= holes[i].volCap(k);
        }
        else if(holes[i].z + holes[i].r < k)
        {
            vol -= holes[i].vol;
        }
    }
    return vol;
}

double BS(double start, int p)
{
    double low = start;
    double high = 1e5;
    while((high - low) > 1e-5)
    {
        double mid = (low + high) * 0.5;
        double vol = getVolTo(mid, p * target);
        if(fabs(vol - target) < 1e-5)
        {
            return low;
        }
        if(vol < target)
        {
            low = mid + 1e-8;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    while(sf2(n, s) == 2)
    {
        total = full;
        REP(i, 0, n)
        {
            scanf("%lf", &holes[i].r);
            scanf("%lf", &holes[i].x);
            scanf("%lf", &holes[i].y);
            scanf("%lf", &holes[i].z);
            holes[i].setVol();
            total -= holes[i].vol;
        }

        target = total / s;

        double prev = 0;
        REP(i, 0, s)
        {
            double cur = BS(prev + 1e-10, i);
            double res = (cur - prev) / 1000.0;
            printf("%.6lf\n", res + EPS);
            prev = cur;
        }
    }

    return 0;
}

/*
0 4
2 5
10000 10000 20000 20000
40000 40000 50000 60000
*/
