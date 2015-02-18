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
typedef long long LL;
typedef unsigned long long ULL;
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
#define LB lower_bound
#define UB upper_bound
#define NL putchar('\n')
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 2005
int tree, high, f;
int acorn[SIZ][SIZ];
int save[SIZ][SIZ];
int dpcas[SIZ][SIZ];

int recur(int t, int h)
{
    if(h <= 0) return 0;

    int& dp = save[t][h];
    int& dpc = dpcas[t][h];
    if(dpc == cas) return dp;

    dp = acorn[t][h] + recur(t, h - 1);
    REPE(i, 1, tree)
    {
        if(i != t) dp = max(dp, acorn[t][h] + recur(i, h - f));
    }

    return dp;
}

int main()
{
#ifdef LOCAL
    freopen("1231.inp", "r", stdin);
#endif // LOCAL

    int m, x;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &tree);
        if(tree == 0) break;

        clr(acorn);
        scanf("%d %d", &high, &f);
        REPE(i, 1, tree)
        {
            scanf("%d", &m);
            while(m--)
            {
                scanf("%d", &x);
                ++acorn[i][x];
            }
        }

        ++cas;
        int res = 0;
        REPE(i, 1, tree)
        res = max(res, recur(i, high));

        printf("%d\n", res);
    }

    return 0;
}
