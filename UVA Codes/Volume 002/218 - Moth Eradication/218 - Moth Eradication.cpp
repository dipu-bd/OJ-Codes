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
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
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
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p>>1)); if(p&1) res*=n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
TEMPLATE T exgcd(T a,T b,T& x,T& y) { if(!b) { x=1; y=0; return a; } else { T g = exgcd(b, a%b, y, x); y -= (a/b)*x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

typedef double T;

struct Point
{
    T x, y;
    Point() { x = 0; y = 0; }
    
    bool operator < (const Point& p) const
    {
        return mp(y, x) < mp(p.y, p.x);
    }  
    bool operator == (const Point& p) const
    {
        return (x == p.x && y == p.y);
    }
};

T cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
T direction(Point a, Point b, Point c) { return cross(a, b) + cross(b, c) + cross(c, a); }

void convexHull(vector<Point>& pts)
{
    //erase all
    ssort(pts);
    pts.erase(unique(all(pts)), pts.end());
    
    //make up-down convex hull
    vector<Point> up, dn;
    for(int i = 0; i < (int)pts.size(); ++i)
    {
        while(up.size() > 1 && direction(up[up.size() - 2], up.back(), pts[i]) <= 0) up.pp();
        while(dn.size() > 1 && direction(dn[dn.size() - 2], dn.back(), pts[i]) >= 0) dn.pp();
        up.pb(pts[i]);
        dn.pb(pts[i]);
    }
    
    //merge
    pts = dn;
    for(int i = up.size() - 2; i >= 1; --i) pts.pb(up[i]);
    
    //first point
    pts.pb(pts[0]);
}

double perimeter(vector<Point>& pts)
{
    double res = 0;
    for(int i = 1; i < (int)pts.size(); ++i)
    {
        res += hypot(pts[i].x - pts[i-1].x, pts[i].y - pts[i-1].y);
    }
    return res;
}   

int main()
{
    int n;
    Point p;
    vector<Point> pts;
    bool newline = false;
    
    while(sf1(n) == 1 && n)
    {
        pts.clear();
        REP(i, 0, n)
        {
            scanf("%lf %lf", &p.x, &p.y);
            pts.pb(p);
        }
        
        convexHull(pts);
        double peri = perimeter(pts);
        
        if(cas > 1) putchar('\n');
        
        printf("Region #%d:\n", cas++); 
        loop(it, pts)
        {
            if(it != pts.begin()) putchar('-');
            printf("(%.1lf,%.1lf)", (it->x + EPS), (it->y + EPS));
        }
        printf("\nPerimeter length = %.2lf\n", peri);
    }
    
    return 0;
}