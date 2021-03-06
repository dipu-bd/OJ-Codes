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
const double EPS = 1E-10;
const double PI = 2.0 * acos(0.0);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> T power(T n, int p) { return (p == 0) ? (T)(1) : (sqr(power(n, p >> 1)) * ((p & 1) * (n - 1) + 1)); }
template<typename T> T bigmod(T n, int p, T m) { return (p == 0) ? (T)(1) : ((sqr(bigmod(n, p >> 1, m)) % m) * ((p & 1) * (n - 1) % m + 1)) % m; }
template<typename T> T GCD(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

int mod = 10007;
const int dim = 4;
ll mat[dim][dim];
ll ans[dim][dim];
ll tmp[dim][dim];
ll base[dim] = { 2, 1, 1, 1 };

void unit()
{
    clr(ans);
    REP(i, 0, dim)
    ans[i][i] = 1;
}

void COPY(ll M[dim][dim])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    ans[i][j] = M[i][j];
}

void cross(ll M[dim][dim])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    {
        tmp[i][j] = 0;
        REP(k, 0, dim)
        tmp[i][j] = (tmp[i][j] + ans[i][k] * M[k][j]) % mod;
    }
    COPY(tmp);
}

void power(int p)
{
    if(p == 0) unit();
    else if(p == 1) COPY(mat);
    else
    {
        power(p >> 1);
        cross(ans);
        if(p & 1) cross(mat);
    }
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int n, x, y;
    while(scanf("%d %d %d", &n, &x, &y) == 3)
    {
        x %= mod;
        y %= mod;

        clr(mat);
        mat[0][0] = 1;
        mat[2][1] = 1;
        mat[3][1] = x;
        mat[3][3] = y;
        mat[0][1] = mat[1][1] = (x * x) % mod;
        mat[0][2] = mat[1][2] = (y * y) % mod;
        mat[0][3] = mat[1][3] = (2 * x * y) % mod;

        power(n - 1);

        int res = 0;
        REP(i, 0, dim)
        res = (res + base[i] * ans[0][i]) % mod;

        printf("%d\n", res);
    }

    return 0;
}
