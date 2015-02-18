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

#define SIZ 1000006

int C[SIZ];
set<int> num;
set<int>::iterator it;

int popmin()
{
    it = num.begin();
    int x = *it; --C[x];
    if(C[x] == 0) num.erase(it);
    return x;
}

int popmax()
{
    it = num.end(); --it;
    int x = *it; --C[x];
    if(C[x] == 0) num.erase(it);
    return x;
}

int main()
{
#ifdef LOCAL
    freopen("11136.inp", "r", stdin);
#endif // LOCAL

    int n, k, x;
    while(scanf("%d", &n) != EOF && n)
    {
        clr(C);
        num.clear();

        ll bill = 0;
        while(n--)
        {
            scanf("%d", &k);
            while(k--)
            {
                scanf("%d", &x);
                num.insert(x);
                ++C[x];
            }
            bill += (popmax() - popmin());
        }

        printf("%lld\n", bill);
    }

    return 0;
}
