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

int num[110];
bool use[20010];

int main()
{
#ifdef LOCAL
    freopen("11063.inp", "r", stdin);
#endif // LOCAL

    int n;
    while(scanf("%d", &n) != EOF)
    {
        REP(i, 0, n) scanf("%d", num + i);

        clr(use);
        bool valid = (1 <= num[0]);

        REP(i, 0, n)
        {
            if(!valid) break;
            REP(j, i, n)
            {
                if(!valid) break;
                if(num[j] < num[i]) valid = 0;
                int s = num[i] + num[j];
                if(use[s]) valid = 0;
                use[s] = 1;
            }
        }

        printf("Case #%d: ", cas++);
        if(valid) printf("It is a B2-Sequence.\n\n");
        else printf("It is not a B2-Sequence.\n\n");
    }

    return 0;
}
