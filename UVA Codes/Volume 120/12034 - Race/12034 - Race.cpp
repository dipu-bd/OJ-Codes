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
#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vii;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(typ,it,v) for(typ::iterator it = v.begin(); it != v.end(); ++it)
#define rloop(typ,it,v) for(typ::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
#define cloop(typ,it,v) for(typ::const_iterator it = v.begin(); it != v.end(); ++it)
#define rcloop(typ,it,v) for(typ::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it)

#define MAX 1000
#define MOD 10056

int pascal[MAX + 10][MAX + 10];
int save[MAX + 10];

void genpascal()
{
    pascal[1][0] = 1;
    pascal[1][1] = 1;

    REPE(i, 2, MAX)
    {
        pascal[i][0] = 1;
        REP(j, 1, i)
        {
            pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % MOD;
        }
        pascal[i][i] = 1;
    }
}

int recur(int n)
{
    if(n == 0 || n == 1) return 1;

    int& dp = save[n];
    if(dp > 0) return dp;

    dp = 1;
    REP(i, 1, n)
    {
        dp = (dp + (pascal[n][i] * recur(n - i)) % MOD) % MOD;
    }

    return dp;
}

int main()
{
    genpascal();

    int test, cas = 1;
    scanf("%d", &test);

    while(test--)
    {
        int n;
        scanf("%d", &n);

        printf("Case %d: %d\n", cas++, recur(n));
    }

    return 0;
}
