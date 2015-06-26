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
//#include <assert.h>
//#define <time.h>
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
typedef vector<int> vii;
typedef vector<pii> vpii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define NEW_LINE printf("\n")
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
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
//variables and functions
const double PI = 2.0 * acos(0.0);
const double EXP1 = exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 1000000
#define MAX 500000

int save[MAX + 5];
int tree[SIZ << 2];

int loopc(int n)
{
    if(n <= 1) return 1;
    if(n <= MAX && save[n]) return save[n];

    int cnt = 1;
    if(n & 1) cnt += loopc(3 * n + 1);
    else cnt += loopc(n >> 1);

    if(n <= MAX) save[n] = cnt;
    return cnt;
}

void build(int nod, int b, int e)
{
    if(b == e)
    {
        tree[nod] = loopc(b);
        return;
    }

    int m = (b + e) >> 1;
    build((nod << 1), b, m);
    build((nod << 1) + 1, 1 + m, e);

    tree[nod] = max(tree[nod << 1], tree[(nod << 1) + 1]);
}

int query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j) return tree[nod];

    int res = 0;
    int m = (b + e) >> 1;
    if(i <= m) res = max(res, query((nod << 1), b, m, i, j));
    if(j > m) res = max(res, query((nod << 1) + 1, 1 + m, e, i, j));

    return res;
}

int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif // LOCAL

    int a, b, x, y, lc;
    build(1, 1, SIZ);

    while(sf2(a, b) == 2)
    {
        if(a < b) { x = a; y = b; }
        else { x = b; y = a; }
        lc = query(1, 1, SIZ, x, y);
        printf("%d %d %d\n", a, b, lc);
    }  
    
    return 0;
}
