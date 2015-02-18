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
#define SZ(v) ((int)v.size())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
#define TEMPLATE template<typename T>
//variables and functions
const double EPS = 1E-10;
const double PI = 2.0 * acos(0.0);
const int CHAR_INF = 0x7F;
const int INT_INF = 0x7F7F7F7F;
const long long LONG_INF = 0X7F7F7F7F7F7F7F7F;
TEMPLATE inline T sqr(T n) { return n * n; }
TEMPLATE inline T pmod(T n, T m) { return ((n % m) + m) % m; }
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p>>1)); if(p&1) res*=n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
TEMPLATE T exgcd(T a,T b,T& x,T& y) { if(!b) { x=1; y=0; return a; } else { T g = exgcd(b, a%b, y, x); y -= (a/b)*x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

struct Rect
{
    int x1, y1, x2, y2, mx, my;
    
    Rect(int u, int l, int b, int r) 
    {
        x1 = u; y1 = l;
        x2 = b; y2 = r;
        mx = (u + b) >> 1;
        my = (l + r) >> 1;
    }
    
    Rect getsect(int id) 
    {
        if(id == 1) //north west
            return Rect(x1, y1, mx, my);
        else if(id == 2) //north east
            return Rect(x1, 1 + my, mx, y2);
        else if(id == 3) //south west
            return Rect(1 + mx, y1, x2, my);
        else if(id == 4) //south east
            return Rect(1 + mx, 1 + my, x2, y2);
        //assert(id < 1 || id > 4);
    } 
};

struct Program
{ 
    Program() { }
    
    int n;
    vii black;
    char img[100][100]; 
    
    void DoWork()
    {
        while(sf1(n) == 1 && n)
        { 
            if(cas > 1) printf("\n");
            printf("Image %d\n", cas++);
            
            if(n > 0)
            {       
                convert();
            }
            else
            {
                revert();
            } 
        } 
    }
    
    void revert()
    {
        n = -n;
        clr(img);
        
        int x;
        while(sf1(x) == 1)
        {
            if(x < 0) break;
            
            //get rectangle
            Rect r(1, 1, n, n);
            for( ; x > 0; x /= 5)
                r = r.getsect(x % 5);
            
            //mark all blacks
            REPE(i, r.x1, r.x2)
            REPE(j, r.y1, r.y2)
            img[i][j] = 1;
        }
        
        //print image
        REPE(i, 1, n)
        {
            REPE(j, 1, n)
            {
                if(img[i][j]) 
                    putchar('*');
                else 
                    putchar('.');
            }
            putchar('\n');
        }
    } 
    
    void convert()
    {
        REPE(i, 1, n)
        {
            scanf(" %s", img[i] + 1);    
            REPE(j, 1, n)
            img[i][j] -= '0';
        }
        
        black.clear();
        char g = DFS(Rect(1, 1, n,  n));
        if(g == 1) black.pb(0);
        
        ssort(black);
        
        //print position of black nodes
        bool nl, sp;
        sp = nl = false;
        REP(i, 0, SZ(black)) 
        {
            if(sp) putchar(' ');
            else sp = true;
            
            printf("%d", black[i]);
            nl = true;
            
            if((i + 1) % 12 == 0) 
            {
                putchar('\n');
                sp = nl = false;
            }
        }
        if(nl) putchar('\n');
        printf("Total number of black nodes = %d\n", SZ(black));
    }
    
    char DFS(Rect r, int d = 0, int b = 1)
    {
        //single cell
        if(r.x1 == r.x2 || r.y1 == r.y2)
        {
            return img[r.x1][r.y1];
        }
        
        //get color of sectors
        char col[5];
        REPE(i, 1, 4)
        {
            col[i] = DFS(r.getsect(i), b * i + d, b * 5);
        }
        
        //check if sector is of same color and has black ones
        char g = col[1];
        bool has = false;
        REPE(i, 1, 4)
        {
            if(col[i] == 1)
                has = true;
            if(g != col[i])
                g = 2;
        }
        
        //if current sector has black ones among other type grab them 
        if(g == 2 && has)
        { 
            REPE(i, 1, 4)
            if(col[i] == 1)
                black.pb(b * i + d);
        }
        
        return g;
    }
    
};

Program mainProgram;
int main() 
{ 
    mainProgram.DoWork();
    return 0; 
}