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
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define fr first
#define sc second
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
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

#define MAX 100005
double save[MAX];

double recur(int n)
{
    if(n == 1) return 0;

    double& dp = save[n];
    if(dp != 0) return dp;

    int cnt = 1;
    int m = sqrt(n);
    REPE(i, 2, m)
    {
        if(!(n % i))
        {
            ++cnt;
            dp += recur(i);
            if(i != m || m * m != n)
                ++cnt, dp += recur(n / i);
        }
    }

    dp = (dp + cnt + 1) / cnt;
    return dp;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int n;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        printf("Case %d: %.7lf\n", cas++, recur(n));
    }

    return 0;
}
