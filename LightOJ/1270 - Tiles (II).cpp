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
#include <time.h>
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
struct RUNTIME
{
    time_t b;
    RUNTIME() { b = clock(); }
    ~RUNTIME() { cerr << "\nRuntime = " << (double)(clock() - b) / CLOCKS_PER_SEC << " seconds"; }
};
/*------------------------------------------------------------------------------------*/

const int oo = 1 << 30;
const int mod = 1000000007;

int test, cas = 1;

int m, n;
char mat[110][110];
int bits[110];
ull save[101][1 << 8];
int _save[101][1 << 8];

int X[6] = { 0b1, 0b11, 0b10, 0b11, 0b01, 0b11 };
int Y[6] = { 0b1, 0b00, 0b11, 0b10, 0b11, 0b01 };

ull recur(int, int);
ull genall(int, int, int, int);

ull genall(int r, int bit, int c = 0, int bit2 = 0)
{
    if(c == n)
    {
        assert(bit + 1 == 1 << n);
        return recur(r + 1, bit2);
    }

    if(bit & (1 << c)) return genall(r, bit, c + 1, bit2);

    ll res = 0;

    if(!(bit2 & (1 << c)))
    {
        res += genall(r, bit | (1 << c), c + 1, bit2 | (1 << c));

        if(c + 1 < n && !(bit2 & (0b11 << c)))
            res += genall(r, bit | (1 << c), c + 1, bit2 | (0b11 << c));

        if(c >= 1 && !(bit2 & (0b11 << (c - 1))))
            res += genall(r, bit | (1 << c), c + 1, bit2 | (0b11 << (c - 1)));
    }

    if(c + 1 < n && !(bit & (0b11 << c)))
    {
        res += genall(r, bit | (0b11 << c), c + 2, bit2);

        if(!(bit2 & (1 << c)))
            res += genall(r, bit | (0b11 << c), c + 2, bit2 | (1 << c));

        if(!(bit2 & (1 << (c + 1))))
           res += genall(r, bit | (0b11 << c), c + 2, bit2 | (1 << (c + 1)));
    }

    return res;
}

ull recur(int r, int bit)
{
    // cout << r << " : " << printbit(bit) << endl;
    if(r == m) return (bit == 0);

    ull& dp = save[r][bit];
    int& dpc = _save[r][bit];
    if(dpc == cas) return dp;

    dpc = cas;
    dp = genall(r, bit, 0, bits[r + 1]);

    return dp;
}

void buildbit()
{
    clr(bits);

    if(m >= n)
    {
        REP(i, 0, m)
        REP(j, 0, n)
        if(mat[i][j] == '#')
            bits[i] |= 1 << j;
    }
    else
    {
        REP(i, 0, n)
        REP(j, 0, m)
        if(mat[j][i] == '#')
            bits[i] |= 1 << j;

        swap(m, n);
    }
}

int main()
{
#ifdef LOCAL
    RUNTIME runtime;
    //freopen("", "r", stdin);
#endif // LOCAL

    sf1(test);
    while(test--)
    {
        sf2(m, n);

        REP(i, 0, m)
        scanf(" %s", mat[i]);

        buildbit();
        ull res = recur(0, bits[0]);

        printf("Case %d: %llu\n", cas++, res);
    }

    return 0;
}
