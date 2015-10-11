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
#define REPNE(i, a, n) for(int i = a;  i >= n; --i)
//input-output
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define deb1(a) cout << a << "\n"
#define deb2(a,b) cout << a << " " << b << "\n"
#define deb3(a,b,c) cout << a << " " << b << " " << c << "\n"
#define deb4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << "\n"
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

//const int oo = 1 << 30;
//const int mod = 1000000007;

int test, cas = 1;

int main()
{
    char ch;
    int res[10];
    int n, m, x, y;
    int board[10][10][2];

    const int RIGHT = 0, DOWN = 1;

    while(sf2(n, m) == 2)
    {
        clr(board);
        REP(i, 0, m)
        {
            scanf(" %c", &ch);
            sf2(x, y);
            if(ch == 'H')
            {
                board[x - 1][y - 1][RIGHT] = 1;
            }
            else
            {
                board[y - 1][x - 1][DOWN] = 1;
            }
        }

        clr(res);
        REP(i, 0, n)
        REP(j, 0, n)
        REP(k, 1, n)
        {
            if(i + k >= n || j + k >= n) break;

            x = i + k;
            y = j + k;
            bool ok = 1;
            REP(p, j, y) //right to left
            {
                if(!ok) break;
                if(!board[i][p][RIGHT]) ok = 0;
                if(!board[x][p][RIGHT]) ok = 0;
            }
            REP(p, i, x) //up to down
            {
                if(!ok) break;
                if(!board[p][j][DOWN]) ok = 0;
                if(!board[p][y][DOWN]) ok = 0;
            }

            if(ok) res[k]++;
        }

        if(cas > 1)
        {
            puts("\n**********************************\n"); //this is fixed size
        }
        printf("Problem #%d\n\n", cas++);

        bool found = 0;
        REP(i, 1, n)
        {
            if(res[i])
            {
                found = 1;
                printf("%d square (s) of size %d\n", res[i], i);
            }
        }
        if(!found)
        {
            puts("No completed squares can be found.");
        }
    }

    return 0;
}
