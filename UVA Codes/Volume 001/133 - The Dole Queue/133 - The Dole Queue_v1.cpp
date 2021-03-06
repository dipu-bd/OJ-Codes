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

int pmod(int a, int m)
{
    if(m) a %= m;
    if(a < 0) a += m;
    return a;
}

int main()
{
#ifdef LOCAL
    freopen("133.inp", "r", stdin);
#endif // LOCAL

    int n, k, m;
    while(scanf("%d %d %d", &n, &k, &m) != EOF && n)
    {
        vii v;
        REPE(i, 1, n) v.pb(i);

        bool comma = false;
        int p = 0, q = n - 1, r;
        while(v.size())
        {
            if(comma) putchar(',');
            else comma = true;

            p = pmod(p + k - 1, v.size());
            q = pmod(q - m + 1, v.size());
            if(p == q)
            {
                printf("%3d", v[p]);
                v.erase(v.begin() + p);
                q = pmod(q - 1, v.size());
                continue;
            }

            printf("%3d", v[p]);
            v.erase(v.begin() + p);
            if(p < q) q = pmod(q - 1, v.size());

            printf("%3d", v[q]);
            v.erase(v.begin() + q);
            if(q < p) p = pmod(p - 1, v.size());
            q = pmod(q - 1, v.size());
        }

        putchar('\n');
    }

    return 0;
}
