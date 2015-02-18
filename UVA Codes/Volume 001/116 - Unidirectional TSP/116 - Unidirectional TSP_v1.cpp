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

int m, n;
int mat[12][102];
int save[12][102];

int pmod(int r)
{
    if(r < 1) r = m;
    if(r > m) r = 1;
    return r;
}

const int R[] = { -1, 0, 1};

int recur(int r = 0, int c = 0)
{
    if(c > n) return 0;

    int& dp = save[r][c];
    if(dp != -1) return dp;

    dp = INT_MAX;
    if(c == 0)
        REPE(i, 1, m) dp = min(dp, recur(i, c + 1));
    else
        REPE(i, 0, 2) dp = min(dp, mat[r][c] + recur(pmod(r + R[i]), c + 1));

    return dp;
}

void printpath(int r = 0, int c = 0)
{
    if(c > n)
    {
        putchar('\n');
        return;
    }

    if(c > 1) putchar(' ');

    if(c == 0)
    {
        REPE(i, 1, m)
        if(recur(r, c) == recur(i, c + 1))
        {
            printpath(i, c + 1);
            return;
        }
    }

    set<int> rows;
    REPE(i, 0, 2) rows.insert(pmod(r + R[i]));
    loop(i, rows)
    {
        if(recur(r, c) == mat[r][c] + recur(*i, c + 1))
        {
            printf("%d", r);
            printpath(*i, c + 1);
            return;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("116.inp", "r", stdin);
#endif // LOCAL

    while(scanf("%d %d", &m, &n) != EOF)
    {
        REPE(i, 1, m) REPE(j, 1, n) scanf("%d", mat[i] + j);

        mem(save, -1);
        int ml = recur();

        printpath();
        printf("%d\n", ml);
    }

    return 0;
}
