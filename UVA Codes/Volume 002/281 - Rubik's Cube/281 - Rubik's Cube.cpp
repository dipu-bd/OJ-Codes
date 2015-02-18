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

enum FACE
{
    _top,
    _down,
    _left,
    _right,
    _front,
    _back,
};

enum ROTATION
{
    CW,
    CCW
};

struct Rect
{
    Rect() { }

    char color[3][3];

    char* operator [] (int i)
    {
        return color[i];
    }

    bool compare(Rect& r, char* chmap)
    {
        REP(i, 0, 3)
        REP(j, 0, 3)
        if(color[i][j] != chmap[r[i][j]])
            return false;
        return true;
    }

    void rotate(ROTATION dir)
    {
        Rect tmp = *this;
        REP(i, 0, 3)
        REP(j, 0, 3)
        {
            if(dir == CW)
                color[i][j] = tmp[3 - j - 1][i];
            else
                color[i][j] = tmp[j][3 - i - 1];
        }
    }
};

struct Cube
{
    Cube() { }

    Rect side[6];

    Rect& operator [] (int i)
    {
        return side[i];
    }

    bool compare(Cube& r, char* chmap)
    {
        REP(i, 0, 6)
        if(!side[i].compare(r.side[i], chmap))
            return false;
        return true;
    }

    void rotate_top()
    {
        side[_top].rotate(CW);
        side[_down].rotate(CCW);
        swap(side[_front], side[_right]);
        swap(side[_right], side[_back]);
        swap(side[_back], side[_left]);
        //left ok
        //front ok
        //right ok
        //back ok
    }
    void rotate_down()
    {
        rotate_top();
        rotate_top();
        rotate_top();
    }
    void rotate_left()
    {
        side[_left].rotate(CW);
        side[_right].rotate(CCW);
        swap(side[_top], side[_back]);
        swap(side[_back], side[_down]);
        swap(side[_down], side[_front]);
        //front ok
        //top
        side[_top].rotate(CW);
        side[_top].rotate(CW);
        //back
        side[_back].rotate(CW);
        side[_back].rotate(CW);
        //down ok
    }
    void rotate_right()
    {
        rotate_left();
        rotate_left();
        rotate_left();
    }
    void rotate_front()
    {
        rotate_top();
        rotate_left();
        rotate_down();
    }
    void rotate_back()
    {
        rotate_down();
        rotate_right();
        rotate_top();
    }
};

Cube cube1, cube2;
char inp1[10][15];
char inp2[10][15];

void setcube(Cube& cube, char inp[10][15])
{
    int x, y;

    //back
    x = 2;
    REP(i, 0, 3)
    {
        y = 2;
        REP(j, 3, 6)
        cube[_back][x][y--] = inp[i][j];
        x--;
    }

    //front
    x = 0;
    REP(i, 6, 9)
    {
        y = 0;
        REP(j, 3, 6)
        cube[_front][x][y++] = inp[i][j];
        ++x;
    }

    //left - top - right - down
    x = 0;
    REP(i, 3, 6)
    {
        y = 2;
        REP(j, 0, 3)
        cube[_left][y--][x] = inp[i][j];

        y = 0;
        REP(j, 3, 6)
        cube[_top][x][y++] = inp[i][j];

        y = 0;
        REP(j, 6, 9)
        cube[_right][y++][2 - x] = inp[i][j];

        y = 2;
        REP(j, 9, 12)
        cube[_down][2 - x][y--] = inp[i][j];

        ++x;
    }
}

bool checkmatch()
{
    char col[] = { 0, 1, 2, 3, 4, 5, 6 };
    do
    {
        if(cube1.compare(cube2, col)) return true;
    }
    while(next_permutation(col + 1, col + 7));

    return false;
}

bool issame()
{
    REP(k, 0, 1)
    {
        REP(i, 0, 4)
        {
            REP(j, 0, 4)
            {
                if(checkmatch()) return true;
                cube1.rotate_top();
            }
            cube1.rotate_left();
        }
        cube1.rotate_top();
        cube1.rotate_left();
    }

    return false;
}

void printcube(Cube& cube)
{
    puts("");
    REP(i, 0, 3)
    {
        REP(f, 0, 6)
        {
            REP(j, 0, 3)
            printf("%d", cube[f][i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
}

int main()
{
    sf1(test);
    while(test--)
    {
        map<char, int> tab1;
        map<char, int> tab2;
        int len1 = 1, len2 = 1;

        REP(i, 0, 9)
        {
            REP(j, 0, 12)
            {
                scanf(" %c", &inp1[i][j]);
                if(isalpha(inp1[i][j]))
                {
                    int& p = tab1[inp1[i][j]];
                    if(!p) p = len1++;
                    inp1[i][j] = p;
                }
            } 
            
            scanf(" %c", &inp2[i][0]);
            REP(j, 0, 12)
            {
                scanf(" %c", &inp2[i][j]);
                if(isalpha(inp2[i][j]))
                {
                    int& p = tab2[inp2[i][j]];
                    if(!p) p = len2++;
                    inp2[i][j] = p;
                }
            }
        }

        setcube(cube1, inp1);
        setcube(cube2, inp2);

        if(issame()) puts("same");
        else puts("different");
    }

    return 0;
}
