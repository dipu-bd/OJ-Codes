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

#define SIZ 1000

int n, m, y;
int curx, cury;
char graph[SIZ][SIZ];
int vis[SIZ][SIZ];
int X[] = { -1, 1, 0, 0};
int Y[] = { 0, 0, 1, -1};


inline bool isout()
{
    return curx < 0 || cury < 0 || curx >= n || cury >= m;
}

inline bool isloop()
{
    return vis[curx][cury] >= 0;
}

inline int getindx(char ch)
{
    if(ch == 'N') return 0;
    if(ch == 'S') return 1;
    if(ch == 'E') return 2;
    return 3;
}

int main()
{
#ifdef LOCAL
    freopen("10116.inp", "r", stdin);
#endif // LOCAL

    while(scanf("%d %d %d", &n, &m, &y) != EOF)
    {
        if(n == 0 && m == 0 && y == 0) break;

        REP(i, 0, n) scanf(" %s", graph[i]);

        mem(vis, -1);
        int cnt = 0;
        bool loop = false;
        curx = 0, cury = y - 1;
        while(!isout())
        {
            if(isloop()) { loop = 1; break; }
            int p = getindx(graph[curx][cury]);
            vis[curx][cury] = cnt++;
            curx += X[p], cury += Y[p];
        }

        if(loop)
        {
            printf("%d step(s) before a loop of ", vis[curx][cury]);
            printf("%d step(s)\n", cnt - vis[curx][cury]);
        }
        else
        {
            printf("%d step(s) to exit\n", cnt);
        }
    }

    return 0;
}

