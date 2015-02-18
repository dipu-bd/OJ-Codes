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
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(it, x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define rloop(it, x) for(__typeof((x).rbegin()) it=(x.rbegin()); it!=(x).rend(); ++it)

#define SIZ 105
vii graph[SIZ];
int sdist[SIZ];
int ddist[SIZ];

void bfs(int* dist, int s)
{
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(q.size())
    {
        s = q.front();
        q.pop();

        int d = dist[s] + 1;
        loop(i, graph[s])
        {
            if(dist[*i] == -1)
            {
                dist[*i] = d;
                q.push(*i);
            }
        }
    }
}

int main()
{
    int test, cas = 1;

    int n, r, u, v;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &r);
        while(r--)
        {
            scanf("%d %d", &u, &v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

        scanf("%d %d", &u, &v);
        mem(sdist, -1);
        mem(ddist, -1);
        bfs(sdist, u);
        bfs(ddist, v);

        int time = 0;
        REP(i, 0, n) time = max(time, sdist[i] + ddist[i]);

        printf("Case %d: %d\n", cas++, time);

        REPE(i, 0, n) graph[i].clear();
    }

    return 0;
}

