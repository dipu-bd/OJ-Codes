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

int n;
char str[1010];
int save[1010][1010];
int has[1010][1010];

int lcs(int i, int j)
{
    if(i == n || j < 0) return 0;

    int& dp = save[i][j];
    int& h = has[i][j];
    if(h == cas) return  dp;

    h = cas;
    if(str[i] == str[j])
    {
        dp = 1 + lcs(i + 1, j - 1);
    }
    else
    {
        dp = max(lcs(i + 1, j), lcs(i, j - 1));
    }

    return dp;
}

int main()
{
    #ifdef LOCAL
    freopen("11151.inp", "r", stdin);
    #endif // LOCAL

    sscanf(gets(str), "%d", &test);
    while(test--)
    {
        ++cas;
        gets(str);

        n = strlen(str);
        int l = lcs(0, n - 1);
        printf("%d\n", l);
    }

    return 0;
}
