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
    int n,  m;
    char mat[20][20];
    int number[20][20];
    map<int, string> res;

    while(sf2(n, m) == 2, n)
    {
        //take input
        clr(mat);
        clr(number);
        REP(i, 0, n)
        scanf(" %s", mat[i]);

        //across test
        REP(i, 0, n)
        {
            bool add = 1;
            REP(j, 0, m)
            {
                if(mat[i][j] == '*')
                {
                    add = 1;
                    continue;
                }
                if(add)
                {
                    add = 0;
                    number[i][j] = 1;
                }
            }
        }

        //down test
        REP(j, 0, m)
        {
            bool add = 1;
            REP(i, 0, n)
            {
                if(mat[i][j] == '*')
                {
                    add = 1;
                    continue;
                }
                if(add)
                {
                    add = 0;
                    number[i][j] = 1;
                }
            }
        }

        //numbering
        int num = 1;
        REP(i, 0, n)
        {
            REP(j, 0, m)
            {
                if(number[i][j])
                    number[i][j] = num++;
            }
        }

        //printing
        if(cas > 1) putchar('\n');
        printf("puzzle #%d:\n", cas++);

        //across print
        res.clear();
        REP(i, 0, n)
        {
            num = -1;
            string add = "";
            REP(j, 0, m)
            {
                if(mat[i][j] == '*')
                {
                    if(num != -1) res[num] = add;
                    num = -1;
                    continue;
                }
                if(num == -1)
                {
                    add.clear();
                    add.pb(mat[i][j]);
                    num = number[i][j];
                }
                else
                {
                    add.pb(mat[i][j]);
                }
            }
            if(num != -1) res[num] = add;
        }
        puts("Across");
        loop(it, res)
        {
            printf("%3d.%s\n", it->fr, it->sc.data());
        }

        //down print
        res.clear();
        REP(j, 0, m)
        {
            num = -1;
            string add = "";
            REP(i, 0, n)
            {
                if(mat[i][j] == '*')
                {
                    if(num != -1) res[num] = add;
                    num = -1;
                    continue;
                }
                if(num == -1)
                {
                    add.clear();
                    add.pb(mat[i][j]);
                    num = number[i][j];
                }
                else
                {
                    add.pb(mat[i][j]);
                }
            }
            if(num != -1) res[num] = add;
        }
        puts("Down");
        loop(it, res)
        {
            printf("%3d.%s\n", it->fr, it->sc.data());
        }
    }

    return 0;
}
