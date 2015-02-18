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
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

char ink[20];
ll save[12][2];

ll recur(int p, bool imax)
{
    if(ink[p] == 0) return 0;

    ll& dp = save[p][imax];
    if(dp != -1) return dp;

    dp = 0;
    int b = (p == 0) ? 1 : 0;
    int e = imax ? ink[p] - '0' : 9;
    for(int i = b; i <= e; ++i)
    {
        dp += 1LL + recur(p + 1, (imax && i == e));
    }

    return dp;
}

bool canmake(ll k, ll m)
{
    ll maxi = k;
    ll mini = 1;
    while(mini <= k) mini *= 10;
    mini /= 10;

    mem(save, -1);
    sprintf(ink, "%lld", k);
    ll sm = recur(0, 1);
    if(m == sm)
    {
        printf("%lld\n", k);
        return true;
    }

    while(sm < m)
    {
        maxi *= 10;
        mini *= 10;
        ll d = maxi - mini;

        if(sm + d < m)
        {
            sm += d;
        }
        else
        {
            d = m - sm - 1;
            printf("%lld\n", mini + d);
            return true;
        }

        if(d == 0) break;
    }

    return false;
}

int main()
{
    ll m, k;

    while(scanf(" %lld %lld", &k, &m) == 2)
    {
        if(!canmake(k, m))
        {
            puts("0");
        }
    }

    return 0;
}
