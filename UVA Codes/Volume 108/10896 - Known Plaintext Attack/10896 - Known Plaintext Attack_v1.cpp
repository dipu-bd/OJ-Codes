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

int pmod(int a)
{
    a %= 26;
    if(a < 0) a += 26;
    return a;
}

int main()
{
#ifdef LOCAL
    freopen("10896.inp", "r", stdin);
#endif // LOCAL

    char word[30];
    char inp[100];

    scanf("%d", &test);
    while(test--)
    {
        scanf(" %[^\n]", inp);

        int sz = 0;
        map<int, vector<string> > wcol;
        for(int i = 0; inp[i]; ++i)
        {
            if(islower(inp[i]))
            {
                word[sz++] = inp[i];
            }
            else if(sz)
            {
                word[sz] = 0;
                wcol[sz].pb(word);
                sz = 0;
            }
        }
        if(sz)
        {
            word[sz] = 0;
            wcol[sz].pb(word);
            sz = 0;
        }

        scanf(" %s", word);

        set<char> keys;
        int len = strlen(word);
        loop(i, wcol[len])
        {
            string& s = *i;

            bool valid = true;
            int d = pmod(s[0] - word[0]);

            REP(i, 1, s.size())
            {
                int m = pmod(s[i] - word[i]);
                if(d != m)
                {
                    valid = false;
                    break;
                }
            }

            if(valid) keys.insert(d + 'a');
        }

        loop(i, keys) putchar(*i);
        putchar('\n');
    }

    return 0;
}
