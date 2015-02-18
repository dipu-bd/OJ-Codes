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

#define LOW -32000
#define UP   32000

int n;
int target;
bool found;
int num[110];
char op[110];
int save[110][64020];

void print()
{
    found = 1;
    printf("%d", num[0]);
    REP(i, 1, n) printf("%c%d", op[i], num[i]);
    printf("=%d\n", target);
}

void backtrack(int p, int cur)
{
    if(found) return;
    if(p == n)
    {
        if(cur == target) print();
        return;
    }

    int& dp = save[p][cur];
    if(dp == cas) return;
    dp = cas;

    //addition
    int tmp = cur + num[p];
    if(LOW <= tmp && tmp <= UP)
    {
        op[p] = '+';
        backtrack(p + 1, tmp);
    }

    //substraction
    tmp = cur - num[p];
    if(LOW <= tmp && tmp <= UP)
    {
        op[p] = '-';
        backtrack(p + 1, tmp);
    }

    //multiplication
    tmp = cur * num[p];
    if(LOW <= tmp && tmp <= UP)
    {
        op[p] = '*';
        backtrack(p + 1, tmp);
    }

    //division
    if(num[p] && !(cur % num[p]))
    {
        op[p] = '/';
        tmp = cur / num[p];
        backtrack(p + 1, tmp);
    }
}

int main()
{
#ifdef LOCAL
    freopen("10400.inp", "r", stdin);
    freopen("10400.out", "w", stdout);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        REP(i, 0, n) scanf("%d", num + i);
        scanf("%d", &target);

        ++cas;
        found = 0;
        backtrack(1, num[0]);
        if(!found) puts("NO EXPRESSION");
    }

    return 0;
}
