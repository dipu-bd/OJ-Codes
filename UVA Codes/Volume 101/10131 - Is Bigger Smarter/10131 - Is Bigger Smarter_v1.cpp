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

#define LIM 1005

struct elep
{
    int n;
    int w;
    int s;

    bool operator < (const elep& r) const
    {
        return w < r.w;
    }
};

int n;
elep data[LIM];
int save[LIM][LIM];

int lis(int i, int p = 0)
{
    if(i == n) return 0;

    int& dp = save[i][p];
    if(dp != -1) return dp;

    dp = lis(i + 1, p); //don't choose
    if(data[p].w < data[i].w && data[p].s > data[i].s) //can choose?
        dp = max(dp, 1 + lis(i + 1, i)); //choose and take the best

    return dp;
}

void printpath(int i = 1, int p = 0)
{
    if(i == n) return;

    if(lis(i, p) == lis(i + 1, i) + 1)
    {
        //printf("%d %d %d\n", data[i].n, data[i].w, data[i].s);
        printf("%d\n", data[i].n);
        printpath(i + 1, i);
    }
    else
    {
        printpath(i + 1, p);
    }
}

int main()
{
#ifdef LOCAL
    freopen("10131.inp", "r", stdin);
#endif // LOCAL

    n = 1;
    elep e;
    data[0].w = INT_MIN;
    data[0].s = INT_MAX;
    while(scanf("%d %d", &e.w, &e.s) != EOF)
    {
        e.n = n;
        data[n++] = e;
    }

    sort(data + 1, data + n);

    mem(save, -1);
    int ml = 0;
    REP(i, 1, n) ml = max(ml, lis(i));

    printf("%d\n", ml);
    printpath();

    return 0;
}
