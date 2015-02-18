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

int b, k, len;
char inp[20];
int val[20];
ll save[65540][21];
int save2[65540][21];

inline int getv(int p)
{
    if(isdigit(inp[p])) return inp[p] - '0';
    return inp[p] - 'A' + 10;
}

ll recur(int mod = 0, int mask = 0)
{
    ll& dp = save[mask][mod];
    int& dp2 = save2[mask][mod];
    if(dp2 == cas) return dp;

    dp = 0;
    dp2 = cas;
    bool none = true;
    int m = 1, p = 0;
    REP(p, 0, len)
    {
        if(!(mask & m))
        {
            none = false;
            dp += recur((mod * b + val[p]) % k, mask | m);
        }
        m <<= 1;
    }

    if(none) dp = (mod == 0);

    return dp;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %s", &b, &k, inp);

        len = strlen(inp);
        REP(i, 0, len) val[i] = getv(i);

        ll res = recur();

        printf("Case %d: %lld\n", cas++, res);
    }

    return 0;
}
