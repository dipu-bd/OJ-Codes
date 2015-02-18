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

char equ[400];

int parseint(int& i)
{
    int num = 0;
    while(isdigit(equ[i]))
        num = num * 10 + equ[i++] - '0';
    return num;
}

int solve()
{
    int x = 0;
    int var = 0;
    int sign = 1;
    for(int i = 0; equ[i];)
    {
        if(equ[i] == '=') sign = -1, ++i;

        int v = 0, s = sign;
        if(equ[i] == '-') s *= -1, ++i;
        if(equ[i] == '+') ++i;

        if(isdigit(equ[i])) v = parseint(i);
        else if(equ[i] == 'x') x += s, ++i;

        if(equ[i] == 'x') x += v * s, ++i;
        else var += v * s;
    }

    if(x == 0) return var ? -1 : 1;

    int res = -var / x;
    if(var % x != 0 && res < 0) res -= 1;

    printf("%d\n", res);
}

int main()
{
#ifdef LOCAL
    freopen("1200.inp", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", equ);
        int v = solve();
        if(v == 1) printf("IDENTITY\n");
        else if(v == -1) printf("IMPOSSIBLE\n");
    }

    return 0;
}
