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

char rule[12][2][100];
char inp[1000];
char tmp[1000];

bool perform(int r)
{
    bool res = 0;
    int i, j, k, m, len;

    len = strlen(rule[r][0]);
    for(i = j = k = 0; inp[i]; ++i)
    {
        tmp[k++] = inp[i];
        if(k - j == len)
        {
            bool match = 1;
            for(m = 0; rule[r][0][m]; ++m)
                if(rule[r][0][m] != tmp[j + m])
                {
                    match = 0;
                    break;
                }

            if(match)
            {
                k = j;
                for(m = 0; rule[r][1][m]; ++m)
                    tmp[k++] = rule[r][1][m];
                res = 1;
            }

            ++j;
        }
    }

    tmp[k] = 0;
    strcpy(inp, tmp);

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("10115.inp", "r", stdin);
#endif // LOCAL

    int n;
    while(scanf("%d ", &n) != EOF && n)
    {
        REP(i, 0, n)
        {
            gets(rule[i][0]);
            gets(rule[i][1]);
        }

        gets(inp);
        REP(i, 0, n) while(perform(i));

        puts(inp);
    }

    return 0;
}
