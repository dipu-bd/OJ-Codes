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

int main()
{
    #ifdef LOCAL
    freopen("11068.inp", "r", stdin);
    #endif // LOCAL

    int a1, b1, c1;
    int a2, b2, c2;
    double del, x, y;

    while(scanf("%d %d %d", &a1, &b1, &c1) != EOF)
    {
        scanf("%d %d %d", &a2, &b2, &c2);

        if(a1 == 0 && b1 == 0 && c1 == 0 &&
           a2 == 0 && b2 == 0 && c2 == 0) break;

        del = a2 * b1 - a1 * b2;
        if(del == 0) printf("No fixed point exists.\n");
        else
        {
            x = (b1 * c2 - b2 * c1) / del;
            y = (c1 * a2 - c2 * a1) / del;
            printf("The fixed point is at %.2lf %.2lf.\n", x, y);
        }
    }

    return 0;
}
