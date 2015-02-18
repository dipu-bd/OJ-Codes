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
typedef unsigned long long ull;
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
#define LB lower_bound
#define UB upper_bound
#define NL putchar('\n')
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

int xl, zl;
char inpz[110];
char inpx[10004];
string save[10004][102];

void printnum(const string& r)
{
    RREPE(i, r.size() - 1, 0)
        putchar(r[i] + '0');
    putchar('\n');
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

int main()
{
#ifdef LOCAL
    freopen("10069.inp", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s %s", inpx, inpz);

        xl = strlen(inpx);
        zl = strlen(inpz);
        REPE(j, 0, zl) save[xl][j] = "\0";
        REPE(i, 0, xl) save[i][zl] = "\1";
        RREPE(i, xl - 1, 0)
        RREPE(j, zl - 1, 0)
        {
            save[i][j] = save[i + 1][j];
            if(inpx[i] == inpz[j])
                add(save[i][j], save[i + 1][j + 1]);
        }

        printnum(save[0][0]);
    }

    return 0;
}
