/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 Problem : 1031 - Easy Game
 Algorithm : DP
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

int n;
int value[110];
int lsum[110];
int rsum[110];
pii save[102][102][2];
int dpcas[102][102][2];

pii recur(int i, int j, int t = 0)
{
    if(j < i) return mp(0, 0);

    pii& dp = save[i][j][t];
    int& dpc = dpcas[i][j][t];
    if(dpc == cas) return dp;

    dpc = cas;
    if(t) dp = mp(0, INT_MIN);
    else dp = mp(INT_MIN, 0);

    REPE(k, i, j)
    {
        //from left
        pii r = recur(k + 1, j, (t + 1) & 1);
        if(!t) //turn for first person
        {
            r.fr += lsum[k] - lsum[i] + value[i];
            if((r.fr - r.sc) > (dp.fr - dp.sc)) dp = r;
        }
        else //turn for second person
        {
            r.sc += lsum[k] - lsum[i] + value[i];
            if((r.sc - r.fr) > (dp.sc - dp.fr)) dp = r;
        }

        //from right
        r = recur(i, k - 1, (t + 1) & 1);
        if(!t) //turn for first person
        {
            r.fr += rsum[k] - rsum[j] + value[j];
            if((r.fr - r.sc) > (dp.fr - dp.sc)) dp = r;
        }
        else //turn for second person
        {
            r.sc += rsum[k] - rsum[j] + value[j];
            if((r.sc - r.fr) > (dp.sc - dp.fr)) dp = r;
        }
    }

    return dp;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    sf1(test);
    while(test--)
    {
        sf1(n);
        REP(i, 0, n) sf1(value[i]);

        lsum[0] = value[0];
        REP(i, 1, n) lsum[i] = value[i] + lsum[i - 1];

        rsum[n - 1] = value[n - 1];
        RREPE(i, n - 2, 0) rsum[i] = value[i] + rsum[i + 1];

        pii res = recur(0, n - 1);
        printf("Case %d: ", cas++);
        printf("%d\n", (res.fr - res.sc));
    }

    return 0;
}
