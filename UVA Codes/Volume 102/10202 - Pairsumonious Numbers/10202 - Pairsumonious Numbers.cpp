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
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
TEMPLATE T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

int n, m;
int num[10];
vii sum, bval;
int mat[10][10];

bool check()
{
    vii test;
    REP(i, 0, n)
    REP(j, i + 1, n)
    test.pb(num[i] + num[j]);

    ssort(test);
    REP(i, 0, m)
    {
        if(test[i] != sum[i]) return false;
    }
    return true;
}

bool process()
{
    clr(mat);
    REP(i, 0, n - 1)
    {
        mat[i][0] = 1;
        mat[i][i + 1] = 1;
    }
    mat[n - 1][n - 2] = 1;
    mat[n - 1][n - 1] = 1;

    //elimination
    REP(k, 0, n - 1)
    {
        REP(i, k + 1, n)
        {
            if(mat[i][k] % mat[k][k]) return false;
            int f = mat[i][k] / mat[k][k];
            REP(j, k, n)
            {
                mat[i][j] -= mat[k][j] * f;
            }
            bval[i] -= bval[k] * f;
        }
    }

    //substitution
    if(bval[n - 1] % mat[n - 1][n - 1]) return false;
    num[n - 1] = bval[n - 1] / mat[n - 1][n - 1];
    RREPE(i, n - 2, 0)
    {
        int v = bval[i];
        REP(j, i + 1, n)
        {
            v -= mat[i][j] * num[j];
        }
        if(v % mat[i][i]) return false;
        num[i] = v / mat[i][i];
    }

    return check();
}

bool backtrack(int p)
{
    if(bval.size() + 1 == n)
    {
        bval.pb(sum[m - 1]);
        if(process()) return true;
        bval.pp();
        return false;
    }
    if(p == m - 1) return false;

    if(backtrack(p + 1)) return true;
    bval.pb(sum[p]);
    if(backtrack(p + 1)) return true;
    bval.pp();
    return false;
}

int main()
{
    int x;
    while(sf1(n) == 1)
    {
        sum.clear();
        bval.clear();

        m = (n * (n - 1)) >> 1;
        REP(i, 0, m)
        {
            sf1(x);
            sum.pb(x);
        }
        ssort(sum);

        bval.pb(sum[0]);
        if(backtrack(1))
        {
            sort(num, num + n);
            printf("%d", num[0]);
            REP(i, 1, n)
            printf(" %d", num[i]);
            putchar('\n');
        }
        else
        {
            puts("Impossible");
        }
    }

    return 0;
}
