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
const double PI = 2.0 * acos(0.0);
const double EXP1 = exp(1);
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
double combi(ll n, ll k) { if(2 * k > n) return combi(n, n - k); double res = 1.0; REP(i, 0, k) res *= (double)(n - i) / (i + 1); return res; }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

int row[20];
int col[20];
int box[20];
char sudoku[20][20];
vpii peers[20][20][3];

const char BLANK = '-';

inline void setv(int& n, int p)
{
    n |= 1 << p;
}
inline void clearv(int& n, int p)
{
    n &= ~(1 << p);
}
inline bool getv(int n, int p)
{
    return (n & (1 << p));
}
inline int bi(int r, int c)
{
    return (r & (~3)) + (c >> 2);
}
inline char toChar(int d) 
{
    return (char)(d + 'A');
}
inline int toInt(char ch)
{
    return (int)(ch - 'A');
}

void color(int r, int c, int d)
{
    sudoku[r][c] = toChar(d);
    setv(row[r], d);
    setv(col[c], d);
    setv(box[bi(r, c)], d);
}

void uncolor(int r, int c, int d)
{
    sudoku[r][c] = BLANK;
    clearv(row[r], d);
    clearv(col[c], d);
    clearv(box[bi(r, c)], d);
}

void init()
{
    REP(i, 0, 16)
    REP(j, 0, 16)
    REP(x, 0, 16)
    REP(y, 0, 16)
    if(!(x == i && y == j))
    {
        if(x == i) peers[i][j][0].pb(mp(x, y));
        if(y == j) peers[i][j][1].pb(mp(x, y));
        if(bi(i, j) == bi(x, y)) peers[i][j][2].pb(mp(x, y));
    }
}

string calculate(int r, int c)
{
    string res;
    
    //gather all possible
    int bit = row[r] | col[c] | box[bi(r, c)];
    REP(d, 0, 16)
    if(!getv(bit, d)) res.pb(d);
    if(res.size() <= 1) return res;
    
    //find hidden single
    REP(d, 0, 16)
    {
        if(!getv(bit, d)) 
        REP(k, 0, 3)
        {
            bool ok = true;
            loop(i, peers[r][c][k])
            if(sudoku[i->fr][i->sc] == BLANK)
            {
                int q = row[i->fr] | col[i->sc] | box[bi(i->fr, i->sc)];
                if(!getv(q, d)) { ok = false; break; }
            }
            if(ok)
            {
                res.clear();
                res.pb(d);
                return res;
            }
        }
    }
    
    //gather all possible
    return res;
}

bool issolved()
{
    REP(i, 0, 16)
    REP(j, 0, 16)
    if(sudoku[i][j] == BLANK)
        return false;
    return true;
}

bool solve()
{ 
    //get best cell to try
    int r, c;
    string best = "";
    REP(i, 0, 16)
    REP(j, 0, 16)
    if(sudoku[i][j] == BLANK)
    {
        string num = calculate(i, j);
        if(num.empty()) return false;
        
        if(best.empty() || num.size() < best.size())
        { best = num; r = i; c = j; }
        
        if(best.size() == 1) break;
    }
    
    if(best.empty()) return issolved();
    
    //recursive call to solve
    loop(it, best)
    {
        color(r, c, *it);
        if(solve()) return true;
        uncolor(r, c, *it);
    }
    
    return false;
}

void printsud()
{
    REP(i, 0, 16)
    {
        REP(j, 0, 16)
        if(sudoku[i][j] == BLANK)
        {
            string num = calculate(i, j);
            loop(t, num) *t = toChar(*t);
            printf("%16s ", num.data());
        }
        else
        {
            printf("%13c[%c] ", ' ', sudoku[i][j]);
        }
        puts("");
    }
}

int main()
{
    init();
    
    bool fr = 1;
    while(!feof(stdin))
    {
        clr(row);
        clr(col);
        clr(box);
        
        REP(i, 0, 16)
        {
            scanf(" %s ", sudoku[i]);
            if(!*sudoku[i]) return 0;
            
            REP(j, 0, 16)
            if(sudoku[i][j] != BLANK)
                color(i, j, toInt(sudoku[i][j])); 
        }
        
        solve();
            
        if(fr) fr = 0;
        else putchar('\n');
        REP(i, 0, 16) puts(sudoku[i]);
    }
    
    return 0;
}
