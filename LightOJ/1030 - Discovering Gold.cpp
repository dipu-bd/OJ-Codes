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

int n;
int arr[103];
double save[103];

double recur(int p)
{
    if(p == n) return (double)arr[n];

    double& dp = save[p];
    if(dp > -1) return dp;

    dp = 0;
    int m = min(p + 6, n);
    for(int i = p + 1; i <= m; ++i)
    {
        dp += recur(i);
    }

    dp = arr[p] + (dp / (m - p));
    return dp;
}

int main()
{
    #ifdef LOCAL
    //freopen("", "r", stdin);
    #endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        REPE(i, 1, n) scanf("%d", arr + i);

        REPE(i, 0, n) save[i] = -1;
        double res = recur(1);

        printf("Case %d: %.7lf\n", cas++, res);
    }

    return 0;
}
