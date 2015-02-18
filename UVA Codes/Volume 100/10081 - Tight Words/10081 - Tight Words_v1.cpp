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

string save[105][10];

double getnum(const string& r)
{
    double res = 0;
    RREPE(i, r.size() - 1, 0)
    res = res * 10 + r[i];
    return res;
}

void add(string& r, string& s)
{
    //fix size
    int sz = max(s.size(), r.size());
    while(r.size() < sz) r.pb(0);
    while(s.size() < sz) s.pb(0);

    //add numbers
    int carry = 0;
    REP(i, 0, sz)
    {
        int sum = carry + r[i] + s[i];
        carry = sum / 10;
        r[i] = sum % 10;
    }
    //add last carry
    if(carry) r.pb(carry);
}

double tight(int n, int k)
{
    REPE(i, 0, k) save[0][i] = "\1";

    //count all
    REPE(i, 1, n - 1)
    REPE(p, 0, k)
    {
        save[i][p] = save[i - 1][p];

        if(p < k) add(save[i][p], save[i - 1][p + 1]);
        if(p > 0) add(save[i][p], save[i - 1][p - 1]);
    }

    //get res
    string res = "\0";
    REPE(i, 0, k) add(res, save[n - 1][i]);

    return getnum(res);
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int k, n;

    while(scanf("%d %d", &k, &n) == 2)
    {
        double cnt = tight(n, k);
        double tot = pow(k + 1, n);
        double res = 100.0 * cnt / tot;
        printf("%.5lf\n", res);
    }

    return 0;
}
