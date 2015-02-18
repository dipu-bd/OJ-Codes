/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
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
template<typename T> T power(T n, int p) { return (p == 0) ? (T)(1) : (sqr(power(n, p >> 1)) * ((p & 1) * (n - 1) + 1)); }
template<typename T> T bigmod(T n, int p, T m) { return (p == 0) ? (T)(1) : ((sqr(bigmod(n, p >> 1, m)) % m) * ((p & 1) * (n - 1) % m + 1)) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

const int d = 2;
ll fib[50];
ll mat[d][d];
ll tmp[d][d];
ll res[d][d];
ll mod = 1000000007LL;

void init()
{
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;

    fib[0] = 1;
    fib[1] = 1;
    REP(i, 2, 50)
    fib[i] = fib[i - 1] + fib[i - 2];
}

void unit()
{
    clr(res);
    REP(i, 0, d)
    res[i][i] = 1;
}

void Copy(ll M[d][d])
{
    REP(i, 0, d)
    REP(j, 0, d)
    res[i][j] = M[i][j];
}

void cross(ll M[d][d])
{
    REP(i, 0, d)
    REP(j, 0, d)
    {
        tmp[i][j] = 0;
        REP(k, 0, d)
        tmp[i][j] += res[i][k] * M[k][j];
        tmp[i][j] %= mod;
    }
    Copy(tmp);
}

void power(ll n)
{
    if(n == 0) unit();
    else if(n == 1) Copy(mat);
    else
    {
        power(n >> 1);
        cross(res);
        if(n & 1) cross(mat);
    }
}

#define IMPOS

int n, m;
ll x, y, k;
ll a0, b0, dl, ans;
ll a1, a2, b1, b2;

bool solve()
{
    //limit exceeded
    if(n > 45 || m > 45) return false;

    a1 = fib[n - 1];
    b1 = fib[n];
    a2 = fib[m - 1];
    b2 = fib[m];

    dl = (a1 * b2) - (a2 * b1);
    a0 = (b2 * x) - (b1 * y);
    b0 = (a1 * y) - (a2 * x);

    //debug3(dl, a0, b0);

    //not integer solution
    if(!dl || a0 % dl || b0 % dl) return false;

    a0 /= dl;
    b0 /= dl;

    //if solution not valid
    if(a0 < 0 || b0 < 0 || !(a0 | b0)) return false;

    power(k - 1);
    a1 = (res[1][0] + res[1][1]) % mod; //f_n
    b1 = (res[0][0] + res[0][1]) % mod; //f_n+1
    ans = (a1 * a0) % mod + (b1 * b0) % mod;

    printf("%lld\n", (ans % mod));
    return true;
}

int main()
{

    init();
    sf1(test);
    while(test--)
    {
        cin >> n >> x >> m >> y >> k;
        printf("Case %d: ", cas++);
        if(!solve()) printf("Impossible\n");
    }

    return 0;
}
