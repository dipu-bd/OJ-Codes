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

bool pos[50];
char inp[100];
char mat[40][20][50];

int conv(char ch)
{
    if(isdigit(ch)) return ch - '0';
    return 10 + ch - 'A';
}

int main()
{
#ifdef LOCAL
    freopen("12586.inp", "r", stdin);
#endif // LOCAL

    int n, q;

    sf2(n, q);
    scanf(" %s", inp);
    REP(i, 0, n)
    {
        int c = conv(inp[i]);
        REP(j, 0, 17) scanf(" %s", mat[c][j]);
    }

    while(q--)
    {
        scanf(" %s", inp);
        int len = strlen(inp);

        clr(pos);
        REP(i, 0, 16)
        REP(j, 0, 43)
        {
            vii flag;
            REP(l, 0, len)
            {
                int c = conv(inp[l]);
                if(mat[c][i][j] == '*') flag.pb(l);
            }
            if(flag.size() == 1)
            {
                pos[flag[0]] = 1;
            }
        }

        printf("Query %d: ", cas++);
        REP(i, 0, len)
        {
            if(pos[i]) putchar('Y');
            else putchar('N');
        }
        putchar('\n');
    }

    return 0;
}
