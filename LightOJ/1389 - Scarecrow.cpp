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
#define sf scanf
#define pf printf
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define FOR(i, a, n) for(int i = a; i < n; ++i)
#define RFOR(i, a, n) for(int i = a; i > n; --i)
#define FORE(i, a, n) for(int i = a; i <= n; ++i)
#define RFORE(i, a, n) for(int i = a; i >= n; --i)
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
#define cloop(typ,it,v) for(typ::const_iterator it = v.begin(); it != v.end(); ++it)
#define rloop(typ,it,v) for(typ::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
#define rcloop(typ,it,v) for(typ::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it)

int n;
char field[110];
int save[110];

int dfs(int p)
{
    while(p < n && field[p] == '#') p++;
    if(p >= n) return 0;

    int& m = save[p];
    if(m > 0) return m;
    return (m = 1 + min(dfs(p + 2), dfs(p + 3)));
}

int main()
{
    int test, cas = 1;
    sf("%d", &test);

    while(test--)
    {
        sf("%d", &n);
        FOR(i, 0, n) sf(" %c", field + i);

        clr(save);
        int cnt = dfs(0);

        pf("Case %d: %d\n", cas++, cnt);
    }

    return 0;
}

