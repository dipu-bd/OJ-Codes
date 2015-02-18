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
#define memsz(a,b,s) memset(a, b, (s))
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
#define loop(it, cont) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define rloop(it, cont) for(__typeof((x).rbegin()) it=(x.rbegin()); it!=(x).rend(); ++it)

int cas = 1;

int n;
int make;
int coin[33];
int save[33][641][641];
int vis[33][641][641];

int getmax(int a, int b, int c)
{
    return (a > b && a > c) ? a : (b > c ? b : c);
}
int getmin(int a, int b, int c)
{
    return (a < b && a < c) ? a : (b < c ? b : c);
}

const int INF = 100000;
int recur(int i = 0, int b1 = 0, int b2 = 0)
{
    if(i == n)
    {
        int b3 = make - (b1 + b2);
        if(b3 < 0) return INF;
        return getmax(abs(b1 - b2), abs(b2 - b3), abs(b1 - b3));
    }

    int& d = save[i][b1][b2];
    int& v = vis[i][b1][b2];
    if(v == cas) return d;

    v = cas;
    d = getmin(recur(i + 1, b1, b2),
               recur(i + 1, b1 + coin[i], b2),
               recur(i + 1, b1, b2 + coin[i]));

    return d;
}

int main()
{
#ifdef LOCAL
    freopen("10482.inp", "r", stdin);
#endif // LOCAL

    int test;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        make = 0;
        REP(i, 0, n)
        {
            scanf("%d", coin + i);
            make += coin[i];
        }

        int r = recur();
        printf("Case %d: %d\n", cas++, r);
    }

    return 0;
}
