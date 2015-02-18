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

int n;
char out[30];
int deg[150];
char choice[150];
vector<char> graph[150];

void backtrack(int p = 0)
{
    if(p == n)
    {
        out[p] = 0;
        puts(out);
        return;
    }

    REPE(v, 'a', 'z')
    {
        if(!choice[v]) continue;

        out[p] = v;
        choice[v] = 0;
        loop(i, graph[v])
        {
            --deg[*i];
            choice[*i] = !deg[*i];
        }

        backtrack(p + 1);

        out[p] = 0;
        choice[v] = 1;
        loop(i, graph[v])
        {
            ++deg[*i];
            choice[*i] = !deg[*i];
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("124.inp", "r", stdin);
#endif // LOCAL

    char u, v;
    bool nl = 0;

    while(!feof(stdin))
    {
        if(scanf(" %c", &u) == EOF) break;
        else ungetc(u, stdin);

        n = 0;
        clr(deg);
        clr(choice);

        while(true)
        {
            while((u = getchar()) == ' ');
            if(u == '\n' || u == EOF) break;
            graph[u].clear();
            choice[u] = 1;
            ++n;
        }

        do
        {
            while((u = getchar()) == ' ');
            if(u == '\n' || u == EOF) break;
            while((v = getchar()) == ' ');
            graph[u].pb(v);
            choice[v] = 0;
            ++deg[v];
        }
        while(getchar() == ' ');

        if(nl) putchar('\n');
        else nl = 1;

        backtrack();
    }

    return 0;
}
