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
#define loop(it, cont) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define rloop(it, cont) for(__typeof((x).rbegin()) it=(x.rbegin()); it!=(x).rend(); ++it)

int main()
{
#ifdef LOCAL
    freopen("11517.inp", "r", stdin);
#endif // LOCAL

    int test;

    int n, m;
    int coin[105];

    const int K = 10010;
    int use[K + 10];

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &m, &n);
        REP(i, 0, n) scanf("%d", coin + i);

        mem(use, 0x6F);
        int inf = use[0];

        use[0] = 0;
        REP(i, 0, n)
        {
            RREPE(j, K - coin[i], 0)
            {
                if(use[j] != inf)
                {
                    int p = j + coin[i];
                    use[p] = min(use[p], use[j] + 1);
                }
            }
        }

        for(int i = m; i < K; ++i)
        {
            if(use[i] < inf)
            {
                printf("%d %d\n", i, use[i]);
                break;
            }
        }
    }

    return 0;
}
