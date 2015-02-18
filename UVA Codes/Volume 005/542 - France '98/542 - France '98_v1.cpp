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

char name[16][50];
double prob[16][16];
double win[4][16];

int main()
{
#ifdef LOCAL
    freopen("542.inp", "r", stdin);
#endif // LOCAL

    REP(i, 0, 16)
    scanf(" %s", name[i]);

    REP(i, 0, 16)
    REP(j, 0, 16)
    {
        scanf(" %lf", &prob[i][j]);
        prob[i][j] /= 100.0;
    }

    //quater
    for(int i = 0; i < 16; i += 2)
    {
        win[0][i] = prob[i][i + 1];
        win[0][i + 1] = prob[i + 1][i];
    }

    //semi
    for(int i = 0; i < 16; i += 4)
    {
        win[1][i] = win[0][i] * (prob[i][i + 2] * win[0][i + 2] + prob[i][i + 3] * win[0][i + 3]);
        win[1][i + 1] = win[0][i + 1] * (prob[i + 1][i + 2] * win[0][i + 2] + prob[i + 1][i + 3] * win[0][i + 3]);
        win[1][i + 2] = win[0][i + 2] * (prob[i + 2][i] * win[0][i] + prob[i + 2][i + 1] * win[0][i + 1]);
        win[1][i + 3] = win[0][i + 3] * (prob[i + 3][i] * win[0][i] + prob[i + 3][i + 1] * win[0][i + 1]);
    }

    //final
    for(int i = 0; i < 16; i += 8)
    {
        REP(j, 0, 4)
        {
            win[2][i + j] = 0;
            REP(k, i + 4, i + 8)
            win[2][i + j] += win[1][k] * prob[i + j][k];
            win[2][i + j] *= win[1][i + j];
        }
        REP(j, 4, 8)
        {
            win[2][i + j] = 0;
            REP(k, i, i + 4)
            win[2][i + j] += win[1][k] * prob[i + j][k];
            win[2][i + j] *= win[1][i + j];
        }
    }

    //worldcup
    REP(i, 0, 8)
    {
        win[3][i] = 0;
        REP(k, 8, 16)
        win[3][i] += win[2][k] * prob[i][k];
        win[3][i] *= win[2][i];
    }
    REP(i, 8, 16)
    {
        win[3][i] = 0;
        REP(k, 0, 8)
        win[3][i] += win[2][k] * prob[i][k];
        win[3][i] *= win[2][i];
    }

    //showres
    REP(i, 0, 16)
    {
        double r = 100.0 * win[3][i];
        printf("%-10s p=%.2lf%%\n", name[i], r);
    }


    return 0;
}
