/*============================
TEAM: SUST_Nexus
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
typedef long long ull;
typedef pair<ll, ll> pll;
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
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------------------------*/

#define MAX

int n;
int fib[25];

int b, e;
char out[50000];

void print(int x, int sz)
{
    int n = fib[x];

    out[sz] = 0;
    b = 0, e = sz;

    //put . first
    REP(i, 1, x)
    {
        out[b++] = '.';
        out[--e] = '.';
    }

    //put # then
    REPE(i, 1, n)
    {
        out[b++] = '#';
        out[--e] = '#';
    }

    //fill rem
    while(b < e)
    {
        out[b++] = '.';
        out[--e] = '.';
    }

    puts(out);
    puts(out);
}

int main()
{
#ifdef LOCAL
    //freopen(".txt", "r", stdin);
#endif // LOCAL

    fib[0] = 0, fib[1] = 1;
    REPE(i, 2, 20) fib[i] = fib[i - 1] + fib[i - 2];

    while(scanf("%d", &n) != EOF)
    {
        if(n == -1) break;
        int sz = 2 * (fib[n] + n - 1);
        REPE(i, 1, n) print(i, sz);
        putchar('\n');
    }

    return 0;
}

