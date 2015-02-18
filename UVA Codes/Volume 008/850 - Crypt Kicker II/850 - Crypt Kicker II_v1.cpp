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
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

bool found;
char key[200];
char inp[110][100];
char known[100] = "the quick brown fox jumps over the lazy dog";

bool isvalid()
{
    REPE(i, 'a', 'z')
    if(!key[i]) return false;
    return true;
}

void findkey(char* str)
{
    int len = strlen(known);
    if(len != strlen(str)) return;

    REP(i, 0, len)
    {
        if(isalpha(known[i]))
        {
            if(!isalpha(str[i])) return;
            key[str[i]] = known[i];
        }
    }

    found = isvalid();
}

void decrypt(char* str)
{
    while(*str)
    {
        if(isalpha(*str)) putchar(key[*str]);
        else putchar(*str);
        ++str;
    }
}

int main()
{
#ifdef LOCAL
    freopen("850.inp", "r", stdin);
#endif // LOCAL

    scanf("%d ", &test);
    while(test--)
    {
        clr(key);
        found = 0;
        int sz = 0;
        while(gets(inp[sz]))
        {
            if(!strlen(inp[sz])) break;
            if(!found) findkey(inp[sz]);
            ++sz;
        }

        if(!found)
            puts("No solution.");
        else
        {
            REP(i, 0, sz)
            {
                decrypt(inp[i]);
                putchar('\n');
            }
        }

        if(test) putchar('\n');
    }

    return 0;
}
