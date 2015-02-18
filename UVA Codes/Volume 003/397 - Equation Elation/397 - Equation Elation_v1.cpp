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

char inp[10000];
char varname[50];

const int _VAR = 0;
const int _OP = 1;

vector<int> val;
vector<char> op;

void showstep()
{
    int i = 0, j = 0;
    printf("%d", val[i++]);
    while(j < op.size())
    {
        printf(" %c ", op[j++]);
        printf("%d", val[i++]);
    }
    printf(" = %s\n", varname);
}

bool takestep()
{
    int i = 0;
    REP(j, 0, op.size())
    {
        if(op[i] == '*' || op[i] == '/')
        {
            if(op[i] == '*')
                val[i] = val[i] * val[i + 1];
            else
                val[i] = val[i] / val[i + 1];

            val.erase(val.begin() + i + 1);
            op.erase(op.begin() + i);
            return true;
        }
        ++i;
    }

    if(op.size())
    {
        if(op[0] == '+')
            val[0] = val[0] + val[1];
        else
            val[0] = val[0] - val[1];

        val.erase(val.begin() + 1);
        op.erase(op.begin());
        return true;
    }

    return false;
}

//12 - 4 * 3 = x
void solve()
{
    val.clear();
    op.clear();

    int sign = 1;
    int next = _VAR;
    int i = 0;
    while(inp[i])
    {
        if(inp[i] == '=') { ++i; break; }

        //integer constants
        if(isdigit(inp[i]))
        {
            int n = 0;
            while(isdigit(inp[i]))
                n = n * 10 + inp[i++] - '0';

            n *= sign;
            val.pb(n);
            next = _OP;
            sign = 1;
            continue;
        }

        if(inp[i] == '+' || inp[i] == '-')
        {
            if(next == _VAR) //unary operators
            {
                sign *= (inp[i] == '-' ? -1 : 1);
            }
            else //binary operator
            {
                sign = 1;
                op.pb(inp[i]);
                next = _VAR;
            }

            ++i;
            continue;
        }

        if(inp[i] == '*' || inp[i] == '/')
        {
            op.pb(inp[i]);
            sign = 1;
            next = _VAR;
            ++i;
            continue;
        }

        //other characters
        ++i;
    }

    int sz = 0;
    while(inp[i] == ' ') ++i;
    while(isalpha(inp[i])) varname[sz++] = inp[i++];
    varname[sz] = 0;

    showstep();
    while(takestep()) showstep();
}

int main()
{
#ifdef LOCAL
    freopen("397.inp", "r", stdin);
#endif // LOCAL

    bool line = 0;
    while(gets(inp))
    {
        if(line) putchar('\n');
        else line = 1;

        solve();
    }

    return 0;
}
