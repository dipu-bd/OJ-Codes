/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 Created on: 2015-04-01-00.51.47, Wednesday
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<pii> vpii;
//always useful
#define unsigned un
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

const int oo = 1 << 30;
const int mod = 1000000007;

int test, cas = 1;

struct Point
{
    int x;
    int y;
    Point(int i = 0, int j = 0) : x(i), y(j) { }
};

struct Rectangle
{
    int x1, y1;
    int x2, y2;
    Rectangle(int i1 = 0, int j1 = 0, int i2 = 0, int j2 = 0) : x1(i1), y1(j1), x2(i2), y2(j2) { }
};

#define SIZ 50005
int p, q, n;
int tree[4800010];
vector<Point> point;
vector<Rectangle> rect;

void compressGrid()
{
    vii nums;
    REP(i, 0, p)
    {
        nums.pb(point[i].x);
        nums.pb(point[i].y);
    }
    REP(i, 0, q)
    {
        nums.pb(rect[i].x1);
        nums.pb(rect[i].y1);
        nums.pb(rect[i].x2);
        nums.pb(rect[i].y2);
    }
    ssort(nums);
    nums.erase(unique(all(nums)), nums.end());
    REP(i, 0, p)
    {
        point[i].x = (int)(LB(all(nums), point[i].x) - nums.begin());
        point[i].y = (int)(LB(all(nums), point[i].y) - nums.begin());
    }
    REP(i, 0, q)
    {
        rect[i].x1 = (int)(LB(all(nums), rect[i].x1) - nums.begin());
        rect[i].y1 = (int)(LB(all(nums), rect[i].y1) - nums.begin());
        rect[i].x2 = (int)(LB(all(nums), rect[i].x2) - nums.begin());
        rect[i].y2 = (int)(LB(all(nums), rect[i].y2) - nums.begin());
    }
    n = (int)nums.size();
    nums.clear();
    ssort(point);
}

void build(int nod, int xb, int yb, int xe, int ye)
{
    if(xb > xe || yb > ye)
    {
        tree[nod] = 0;
        return;
    }
    if(xb == xe && yb == ye)
    {
        int p = LB(all(point), mp(xb, yb)) - point.begin();
        tree[nod] = (p < point.size() && point[p].x == xb && point[p].y == yb);
        return;
    }

    int nc1 = (nod << 2) - 2;
    int nc2 = (nod << 2) - 1;
    int nc3 = (nod << 2);
    int nc4 = (nod << 2) + 1;
    int xm = (xb + xe) >> 1;
    int ym = (yb + ye) >> 1;

    build(nc1, xb, yb, xm, ym);
    build(nc1, xb, ym + 1, xm, ye);
    build(nc2, xm + 1, yb, xe, ym);
    build(nc2, xm + 1, ym + 1, xe, ye);

    tree[nod] = tree[nc1] + tree[nc2] + tree[nc3] + tree[nc4];
}

int main()
{
    sf1(test);
    while(test--)
    {
        sf2(p, q);
        REP(i, 0, p)
        {
            sf2(point[i].x, point[i].y);
        }
        REP(i, 0, q)
        {
            sf2(rect[i].x1, rect[i].y1);
            sf2(rect[i].x2, rect[i].y2);
        }

        compressGrid();
        build_tree();

    }

    return 0;
}
