/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
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
typedef pair<int, int> pii;
typedef vector<int> vii;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)

typedef pair<ll, ll> pll; //first = count of zeros, second = number of ways

string num;
pll save[15][2][2];

pll recur(int pos = 0, bool imax = 1, bool beg = 1)
{
    if(pos == num.size()) return mp(0LL, 1LL);

    pll& dp = save[pos][imax][beg];
    if(dp.first != -1) return dp;

    dp.first = dp.second = 0;
    int stop = imax ? num[pos] : 9;

    REPE(i, 0, stop)
    {
        pll r = recur(pos + 1, i == stop && imax, i == 0 && beg);
        dp.first += r.first;
        dp.second += r.second;
        if(i == 0 && !beg) dp.first += r.second;
    }

    return dp;
}

void convert(ll n)
{
    if(n == 0) { num.clear(); return; }
    convert(n / 10);
    num.pb(n % 10);
}

int main()
{
    int test, cas = 1;

    ll m, n;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lld %lld", &m, &n);

        ll rm = -1; //count m = 0 as 1
        if(m > 0)
        {
            mem(save, -1);
            convert(m - 1);
            rm = recur().first;
        }

        mem(save, -1);
        convert(n);
        ll rn = recur().first;

        printf("Case %d: %lld\n", cas++, rn - rm);
    }

    return 0;
}
