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

int len;
int len1, len2;
int pi[110];
char str1[110];
char str2[110];
char bad[110];
int save[110][110][110];
char _save[110][110][110];

void build_lps()
{
    int k = 0;
    for(int i = 2; i <= len; ++i)
    {
        while(k > 0 && bad[i] != bad[k + 1]) k = pi[k];
        if(bad[i] == bad[k + 1]) ++k;
        pi[i] = k;
    }
}

int getnext(int i, int p)
{
    int t = p;
    while(t > 0 && bad[t + 1] != str1[i]) t = pi[t];
    if(bad[t + 1] == str1[i]) ++t;
    return t;
}

int recur(int i, int j, int p)
{
    //base
    if(i > len1 || j > len2 || p == len)
        return 0;

    //save
    int& dp = save[i][j][p];
    char& dpc = _save[i][j][p];
    if(dpc) return dp;
    dp = 0;

    //process
    if(str1[i] == str2[j])
    {
        int t = getnext(i, p);
        if(t < len)
        {
            dpc = 1;
            dp = recur(i + 1, j + 1, t) + 1;
        }
    }

    int a = recur(i + 1, j, p);
    int b = recur(i, j + 1, p);
    if(a >= dp) dp = a, dpc = 2;
    if(b >= dp) dp = b, dpc = 3;
    return dp;
}

void path_print(int i, int j, int p)
{
    if(i > len1 || j > len2 || p == len)
    {
        return;
    }

    char& dpc = _save[i][j][p];

    if(dpc == 1)
    {
        putchar(str1[i]);
        path_print(i + 1, j + 1, getnext(i, p));
    }
    else if(dpc == 2)
    {
        path_print(i + 1, j, p);
    }
    else if(dpc == 3)
    {
        path_print(i, j + 1, p);
    }
}

int main()
{
    scanf(" %s", str1 + 1);
    scanf(" %s", str2 + 1);
    scanf(" %s", bad + 1);
    len = strlen(bad + 1);
    len1 = strlen(str1 + 1);
    len2 = strlen(str2 + 1);

    build_lps();
    int res = recur(1, 1, 0);
    if(res) path_print(1, 1, 0);
    else printf("%d", res);
    putchar('\n');

    return 0;
}
