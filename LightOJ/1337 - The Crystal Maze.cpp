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
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------------------------*/

int m, n, q, num;
int test, cas = 1;
char maze[505][505];
int vis[505][505];

int dfs(int i, int j)
{
    if(i < 1 || i > m || j < 1 || j > n) return 0;
    if(vis[i][j] || maze[i][j] == '#') return 0;

    vis[i][j] = num;
    return  (maze[i][j] == 'C') +
            dfs(i + 1, j) +
            dfs(i - 1, j) +
            dfs(i, j + 1) +
            dfs(i, j - 1);
}

int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d", &m, &n, &q);
        REPE(i, 1, m) scanf(" %s", maze[i] + 1);

        clr(vis);
        vii block;
        num = 1;
        REPE(i, 1, m)
        REPE(j, 1, n)
        if(!vis[i][j])
        {
            block.pb(dfs(i, j));
            ++num;
        }

        printf("Case %d:\n", cas++);
        while(q--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            int& v = vis[x][y];
            printf("%d\n", block[v - 1]);
        }
    }

    return 0;
}

