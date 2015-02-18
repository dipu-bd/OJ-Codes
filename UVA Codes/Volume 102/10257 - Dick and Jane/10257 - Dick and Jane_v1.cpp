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

int s, p, y, j;

bool hold(int spot, int puff, int yer)
{
    return spot >= s + puff &&
           puff >= p + yer &&
           spot >= y + yer &&
           puff + spot + yer == 12 + j;
}

int main()
{
#ifdef LOCAL
    freopen("10257.inp", "r", stdin);
#endif // LOCAL

    int yer, puff, spot;
    while(scanf("%d %d %d %d", &s, &p, &y, &j) != EOF)
    {
        yer = (12 + j - p - y) / 3;
        puff = yer + p;
        spot = yer + y;

        bool out = false;
        REP(i, 0, 2) REP(j, 0, 2) REP(k, 0, 1)
        {
            if(out) break;
            if(hold(spot + i, puff + j, yer + k))
            {
                out = true;
                printf("%d %d %d\n", spot + i, puff + j, yer + k);
            }
        }
    }

    return 0;
}
