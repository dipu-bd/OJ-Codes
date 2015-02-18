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
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
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
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)

char str[100];
ll save[62][62];

ll recur(int i, int j)
{
    if(j < i) return 0;

    ll& dp = save[i][j];
    if(dp != -1) return dp;

    dp = 0;

    if(str[i] == str[j])
        dp = recur(i + 1, j - 1) + 1;

    dp += recur(i + 1, j) + //del first
          recur(i , j - 1) - //del second
          recur(i + 1, j - 1); //substract duals

    return dp;
}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", str);
        mem(save, -1);
        int len = strlen(str);
        ll res = recur(0, len - 1);
        printf("Case %d: %lld\n", cas++, res);
    }

    return 0;
}
