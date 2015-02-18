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

#define SIZ (1 << 21)

int n, sum;
int arr[22];
char save[SIZ];

bool recur(int mask = 0)
{
    char& dp = save[mask];
    if(dp != -1) return dp;

    int s = 0, t = 0;
    REP(i, 0, n)
    {
        if(mask & (1 << i))
        {
            s += arr[i];
            ++t;
        }
    }

    if(t == n)  return !(s - 4 * sum);
    if(s >= 4 * sum) return 0;

    dp = 0;
    s %= sum;
    REP(i, 0, n)
    {
        int p = (1 << i);
        if(!(mask & p) && (s + arr[i] <= sum))
        {
            dp = recur(mask | p);
            if(dp == 1) break;
        }
    }

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

        sum = 0;
        REP(i, 0, n)
        {
            scanf("%d", arr + i);
            sum += arr[i];
        }
        sum >>= 2;

        mem(save, -1);
        bool ans = recur();

        if(ans) puts("yes");
        else puts("no");
    }

    return 0;
}
