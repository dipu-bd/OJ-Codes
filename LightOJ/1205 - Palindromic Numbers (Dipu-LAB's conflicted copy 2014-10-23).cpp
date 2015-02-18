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
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------------------------*/

int run = 0;
char num[20];
ll save[20][20][2];
int curcas[20][20][2];

ll recur(int i, int j, bool imax = 1)
{
    if(i > j) return 1;

    ll& dp = save[i][j][imax];
    int& ret = curcas[i][j][imax];
    if(ret == run) return dp;

    dp = 0;
    ret = run;

    int b = (i == 0);
    int e = imax ? num[i] - '0' : 9;

    //build lower size numbers
    if(i == 0 && i < j)
    {
        dp += recur(i, j - 1, 0);
    }

    //build current size numbers upto max - 1
    REP(p, b, e)
    {
        dp += recur(i + 1, j - 1, 0);
    }

    bool cont = (e >= b);
    //if maximum taken until now
    if(imax && (j - i) <= 1)
    {
        //if range[j, len] >= range[i, 0]_rev we can continue
        for(int p = i, q = j; cont && p >= 0; --p, ++q)
        {
            if(num[q] > num[p]) break;
            cont = (num[q] == num[p]);
        }
    }
    if(cont)
    {
        dp += recur(i + 1, j - 1, imax);
    }

    return dp;
}

ll getcount(ll n)
{
    if(n < 0) return 0;
    if(n == 0) return 1;

    ++run;
    sprintf(num, "%lld", n);
    return 1 + recur(0, strlen(num) - 1);
}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        ll a, b, r1, r2;
        scanf("%lld %lld", &a, &b);
        if(a > b) swap(a, b);

        r1 = getcount(b);
        r2 = getcount(a - 1);

        printf("Case %d: %lld\n", cas++, r1 - r2);
    }

    return 0;
}
