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
typedef pair<ll, ll> pll;
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

#define SIZ 1000006

int ind;
int n, x;
vii pos[SIZ];
int lcount[SIZ];
int rcount[SIZ];
map<int, int> indx;
int tree[SIZ << 2];

void add(int v, int p)
{
    int& x = indx[v];
    if(!x) x = ++ind;
    pos[x].pb(p);
}

void update(int nod, int b, int e, int p)
{
    if(b == e)
    {
        ++tree[nod];
        return;
    }

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    if(p <= m) update(l, b, m, p);
    else update(r, 1 + m, e, p);

    tree[nod] = tree[l] + tree[r];
}

ll query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j)
    {
        return tree[nod];
    }

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    ll cnt = 0;
    if(i <= m) cnt += query(l, b, m, i, j);
    if(j > m) cnt += query(r, 1 + m, e, i, j);

    return cnt;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    //get numbers
    sf1(n);
    REPE(i, 1, n)
    {
        sf1(x);
        add(x, i);
    }

    //count left and right
    int lim = 0;
    REPE(j, 1, ind)
    {
        REP(i, 0, pos[j].size())
        {
            int v = pos[j][i];
            lcount[v] = i + 1;
            rcount[v] = pos[j].size() - i;
        }
        lim = max(lim, (int)pos[j].size());
    }

    //REPE(i, 1, n) printf("%2d", i); puts("");
    //REPE(i, 1, n) printf("%2d", lcount[i]); puts("");
    //REPE(i, 1, n) printf("%2d", rcount[i]); puts("");

    ll res = 0;
    REPE(i, 1, n)
    {
        res += query(1, 1, lim, rcount[i] + 1, lim);
        update(1, 1, lim, lcount[i]);
    }

    printf("%I64d\n", res);

    return 0;
}
