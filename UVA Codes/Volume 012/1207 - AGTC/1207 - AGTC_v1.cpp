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

#define SIZ 1005

int n, m;
char str1[SIZ], str2[SIZ];
int save[SIZ][SIZ];

int recur(int i, int j)
{
    if(i >= n) return m - j;
    if(j >= m) return n - i;

    int& dp = save[i][j];
    if(dp != -1) return dp;

    if(str1[i] == str2[j])
    {
        dp = recur(i + 1, j + 1);
    }
    else
    {
        dp = INT_MAX;
        dp = min(dp, recur(i + 1, j) + 1);
        dp = min(dp, recur(i, j + 1) + 1);
        dp = min(dp, recur(i + 1, j + 1) + 1);
    }

    return dp;
}

int main()
{
    #ifdef LOCAL
    freopen("1207.inp", "r", stdin);
    #endif // LOCAL

    while(scanf("%d %s %d %s", &n, str1, &m, str2) != EOF)
    {
        mem(save, -1);
        printf("%d\n", recur(0, 0));
    }

    return 0;
}
