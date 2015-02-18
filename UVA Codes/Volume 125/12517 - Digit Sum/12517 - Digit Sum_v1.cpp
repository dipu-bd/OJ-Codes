#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector<int> vii;
typedef vector<pii> vpii;

#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
#define memsz(a, b, n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i > n; --i)
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d%d", &a, &b)
#define sf3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define ins insert
#define mp make_pair
#define IT iterator
#define allof(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i = (x).rbegin(); i != (x).rend(); ++i)

const double PI = 2.0 * acos(0.0);
const double EXP1 =  exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }


int test, cas = 1;

typedef pair<ll, ll> pll;

int len;
char maxl[15];
pll save[15][2];

pll recur(int p, bool maxi)
{
    if(p == len) return mp(0, 1);

    pll& dp = save[p][maxi];
    if(dp.fr != -1) return dp;

    int b = 0;
    int e = maxi ? maxl[p] - '0' : 9;

    dp = mp(0, 0);
    REPE(i, b, e)
    {
        pll r = recur(p + 1, maxi && i == e);
        dp.fr += i * r.sc + r.fr;
        dp.sc += r.sc;
    }

    return dp;
}

int main()
{
#ifdef LOCAL
    //freopen("D.txt", "r", stdin);
#endif

    int a, b;
    while(sf2(a, b) == 2)
    {
        if(a == 0 && b == 0) break;

        if(a > b) swap(a, b);

        pll ra, rb;

        if(a > 1)
        {
            --a;
            mem(save, -1);
            sprintf(maxl, "%d", a);
            len = strlen(maxl);
            ra = recur(0, 1);
        }
        else
        {
            ra = mp(0, 0);
        }

        mem(save, -1);
        sprintf(maxl, "%d", b);
        len = strlen(maxl);
        rb = recur(0, 1);

        ll res = rb.fr - ra.fr;
        printf("%lld\n", res);
    }

    return 0;
}







