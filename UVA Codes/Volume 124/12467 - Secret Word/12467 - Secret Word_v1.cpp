/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
//#include <bits/stdc++.h>
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
//#include <assert.h>
//#include <time.h>
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
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<pii> vpii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define allof(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
const double PI = 2.0 * acos(0.0);
const double EXP1 = exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 1000006

int len;
char inp[SIZ];
char rev[SIZ];
int pi[SIZ];

void computepi()
{
    pi[1] = 0;
    int k = 0;
    REPE(i, 2, len)
    {
        while(k > 0 && inp[k + 1] != inp[i])
            k = pi[k];
        if(inp[k + 1] == inp[i]) k++;
        pi[i] = k;
    }
}

int maxmatch()
{
    int mx = 0;
    int q = 0;
    REPE(i, 1, len)
    {
        while(q > 0 && inp[q + 1] != rev[i])
            q = pi[q];
        if(inp[q + 1] == rev[i]) q++;
        if(mx < q) mx = q;
        if(q == len) q = pi[q];
    }
    return mx;
}

int main()
{
    #ifdef LOCAL
    freopen("12467.inp", "r", stdin);
    #endif // LOCAL

    sf1(test);
    while(test--)
    {
        scanf(" %s", inp + 1);

        len = strlen(inp + 1);
        REPE(i, 1, len)
        rev[len - i + 1] = inp[i];

        computepi();
        int m = maxmatch();

        rev[len + 1] = 0;
        puts(rev + len - m + 1);
    }

    return 0;
}
