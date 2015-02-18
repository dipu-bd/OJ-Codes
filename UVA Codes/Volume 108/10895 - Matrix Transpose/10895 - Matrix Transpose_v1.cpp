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
typedef unsigned long long ull;
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
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 10003
int inp[SIZ];
vii graph[SIZ];
vii elem[SIZ];

int main()
{
    #ifdef LOCAL
    freopen("10895.inp", "r", stdin);
    #endif // LOCAL

    int m, n, t, x;
    while(scanf("%d %d", &m, &n) != EOF)
    {
        REPE(i, 1, n)
        {
            graph[i].clear();
            elem[i].clear();
        }

        REPE(i, 1, m)
        {
            scanf("%d", &t);
            REP(j, 0, t)
            {
                scanf("%d", &x);
                graph[x].pb(i);
                inp[j] = x;
            }
            REP(j, 0, t)
            {
                scanf("%d", &x);
                elem[inp[j]].pb(x);
            }
        }

        printf("%d %d\n", n, m);
        REPE(i, 1, n)
        {
            t = graph[i].size();
            printf("%d", t);

            loop(it, graph[i]) printf(" %d", *it);
            putchar('\n');

            x = 0;
            loop(it, elem[i])
            {
                if(x) putchar(' ');
                else x = 1;
                printf("%d", *it);
            }
            putchar('\n');
        }
    }

    return 0;
}
