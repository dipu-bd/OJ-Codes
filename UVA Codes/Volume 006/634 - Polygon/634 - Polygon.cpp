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

typedef int T;

struct Point
{
    T x, y;
    Point() {} 
    Point(T a, T b) : x(a), y(b) {}  
};

T cross(Point a, Point b) 
{ 
    return a.x * b.y - a.y * b.x; 
}

int direction(Point a, Point b, Point c) 
{ 
    T d = cross(a, b) + cross(b, c) + cross(c, a); 
    if(d < 0) return -1;
    if(d > 0) return 1;
    return 0;
}

bool  onsegment(Point p1, Point p2, Point q)
{
    return min(p1.x, p2.x) <= q.x && q.x <= max(p1.x, p2.x) && 
           min(p1.y, p2.y) <= q.y && q.y <= max(p1.y, p2.y); 
}

bool intersect(Point p1, Point p2, Point q1, Point q2)
{
    int o1 = direction(p1, p2, q1);
    int o2 = direction(p1, p2, q2);
    int o3 = direction(q1, q2, p1);
    int o4 = direction(q1, q2, p2);
     
    if(o1 != o2 && o3 != o4) return true;
    
    if(o1 == 0 && onsegment(p1, p2, q1)) return true;
    if(o2 == 0 && onsegment(p1, p2, q2)) return true;
    if(o3 == 0 && onsegment(q1, q2, p1)) return true;
    if(o4 == 0 && onsegment(q1, q2, p2)) return true;
    
    return false;
}

vector<Point> poly;

bool isInside(Point p)
{
    bool in = 0;
    Point mxp = Point(100000, p.y);
    
    int n = poly.size();
    REP(i, 0, n)
    {
        int j = ((i + 1) % n);
        if (intersect(poly[i], poly[j], p, mxp)) 
            in = !in; 
    }
    
    return in;
}

int main()
{
    int n;
    Point p;
    
    while(sf1(n)==1 && n)
    {
        poly.clear();
        while(n--)
        {
            sf2(p.x, p.y);
            poly.pb(p); 
        }

        sf2(p.x, p.y);
        if(isInside(p))
            puts("T");
        else 
            puts("F");
    }
    
    return 0;
}