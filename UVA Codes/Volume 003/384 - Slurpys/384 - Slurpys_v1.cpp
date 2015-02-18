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

typedef pair<bool, char*> pbc;

pbc slump(char *str)
{
    if(*str == 0) return mp(0, str);

    if(!(*str == 'D' || *str == 'E')) return mp(0, str);

    ++str; //first is either D or E
    if(*str != 'F') return mp(0, str);

    while(*str == 'F')  ++str; //take out all sequence of F

    if(*str == 'G') //end of slump
    {
        ++str;
        return mp(1, str);
    }

    return slump(str); //if not end, then follwed by another slump
}

pbc slimp(char *str)
{
    if(*str == 0) return mp(0, str);
    if(*str != 'A') return mp(0, str);

    ++str;
    if(*str == 'H') //two character slimp
    {
        ++str;
        return mp(1, str);
    }

    pbc r = mp(0, str);
    if(*str == 'B')
    {
        ++str;
        r = slimp(str); //B is followed by a slimp
    }
    else
    {
        r = slump(str); //if not B then A is followed by a slump
    }

    if(!r.fr) return r;

    str = r.sc;
    if(*str != 'C') return mp(0, str);

    ++str;
    return mp(1, str);
}

bool slurpy(char* str)
{
    pbc a = slimp(str);
    if(!a.fr) return false;

    pbc b = slump(a.sc);
    if(!b.fr) return false;

    return (*b.sc == 0);
}

int main()
{
#ifdef LOCAL
    freopen("384.inp", "r", stdin);
#endif // LOCAL

    puts("SLURPYS OUTPUT");

    char inp[100];
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", inp);
        slurpy(inp) ? puts("YES") : puts("NO");
    }

    puts("END OF OUTPUT");

    return 0;
}
