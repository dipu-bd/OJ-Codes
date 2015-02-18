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

int w, k, sz;
int yval[105];
int freq[105];
int save[105][105];

int recur(int p, int m)
{
    if(p == sz || m == k) return 0;

    int& dp = save[p][m];
    if(dp != -1) return dp;

    //don't take this value
    dp = recur(p + 1, m);
    //take this value
    int cnt = 0;
    int d = yval[p] + w;
    while(p < sz && yval[p] <= d) cnt += freq[p++];
    dp = max(dp, cnt + recur(p, m + 1));

    return dp;
}

int main()
{
    int test, cas = 1;
    int n, x, y;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d", &n, &w, &k);

        map<int, int> point;
        while(n--)
        {
            scanf("%d %d", &x, &y);
            ++point[y];
        }

        sz = 0;
        loop(i, point)
        {
            yval[sz] = i->_a;
            freq[sz] = i->_b;
            ++sz;
        }

        mem(save, -1);
        int res = recur(0, 0);

        printf("Case %d: %d\n", cas++, res);
    }

    return 0;
}
