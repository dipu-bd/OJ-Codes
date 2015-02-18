#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<pii> vpii;
typedef map<int, int> mpii;
#define gcd(a, b) __gcd(a, b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define ins insert
#define mp make_pair
#define IT iterator
#define allof(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i = (x).rbegin(); i != (x).rend(); ++i)
const double PI = 2.0 * acos(0.0);
const double EXP = exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
int test, cas = 1;

#define SIZ 1003

int n, b, ind;
map<string, int> type;
mpii qual[SIZ];
set<int> allq;

bool ispos(int q)
{
    int tot = 0;
    REPE(i, 1, ind)
    {
        bool pos = false;
        int mini = INT_MAX;
        rloop(it, qual[i])
        {
            if(it->fr < q) break;
            pos = true;
            mini = min(it->sc, mini);
        }
        if(!pos) return false;
        tot += mini;
    }
    return (tot <= b);
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif

    int p, q;
    string tn, pn;

    sf1(test);
    while(test--)
    {
        sf2(n, b);

        ind = 0;
        REP(i, 0, n)
        {
            cin >> tn >> pn;
            sf2(p, q);
            allq.ins(q);

            int& t = type[tn];
            if(!t) t = ++ind;

            if(!qual[t].count(q))
            {
                qual[t][q] = p;
            }
            else
            {
                qual[t][q] = min(qual[t][q], p);
            }
        }

        int res = 0;
        rloop(i, allq)
        if(ispos(*i))
        {
            res = *i;
            break;
        }

        printf("%d\n", res);

        allq.clear();
        type.clear();
        REPE(i, 0, ind) qual[i].clear();
    }

    return 0;
}