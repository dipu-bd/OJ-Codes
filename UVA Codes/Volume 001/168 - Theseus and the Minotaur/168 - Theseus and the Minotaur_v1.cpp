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

char inp[1000];
vii graph[100];
char state[100];

void traverse(char u, char v, int k)
{
    int p = 0;
    while(1)
    {
        if(p > 0 && !(p % k))
        {
            state[u] = 1;
            if(p > k) putchar(' ');
            putchar(u);
        }

        bool cont = false;
        loop(it, graph[v])
        {
            if(*it == u || state[*it]) continue;
            ++p;
            u = v;
            v = *it;
            cont = true;
            break;
        }
        if(cont) continue;

        if(p >= k) putchar(' ');
        putchar('/');
        putchar(v);
        putchar('\n');
        break;
    }
}

int main()
{
#ifdef LOCAL
    freopen("168.inp", "r", stdin);
#endif // LOCAL

    int k;
    char u, v;
    while(scanf(" %s", inp) != EOF)
    {
        if(*inp == '#') break;

        clr(state);
        REPE(i, 'A', 'Z')
        graph[i].clear();

        for(int i = 0; inp[i]; ++i)
        {
            u = inp[i];
            if(u == '.') break;
            if(!isalpha(u)) continue;
            for(++i; inp[i]; ++i)
            {
                v = inp[i];
                if(v == ';' || v == '.') break;
                if(!isalpha(v)) continue;
                graph[u].pb(v);
            }
        }

        scanf(" %c %c %d", &v, &u, &k);
        traverse(u, v, k);
    }

    return 0;
}
