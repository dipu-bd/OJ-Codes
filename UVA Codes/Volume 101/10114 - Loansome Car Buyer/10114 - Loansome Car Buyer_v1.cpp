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

int mon, rec, num;
double down, loan;
double deprec[110];

int calculate()
{
    double pay = loan / mon;
    double car = loan + down;

    loan += pay;
    REPE(i, 0, mon)
    {
        loan -= pay;
        car *= 1 - deprec[i];
        if(car > loan) return i;
    }

    return mon;
}

int main()
{
#ifdef LOCAL
    freopen("10114.inp", "r", stdin);
#endif // LOCAL

    while(scanf("%d %lf %lf %d", &mon, &down, &loan, &rec) != EOF)
    {
        if(mon < 0) break;

        int b = 0;
        double dep;
        while(rec--)
        {
            scanf("%d %lf", &num, &dep);
            REP(i, b + 1, num)  deprec[i] = deprec[b];
            deprec[num] = dep;
            b = num;
        }
        REPE(i, b + 1, mon) deprec[i] = deprec[b];

        int res = calculate();

        if(res == 1) printf("1 month\n");
        else printf("%d months\n", res);
    }

    return 0;
}
