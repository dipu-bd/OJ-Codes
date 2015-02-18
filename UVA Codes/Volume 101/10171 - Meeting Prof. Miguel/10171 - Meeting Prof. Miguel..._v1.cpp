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
typedef long long LL;
typedef unsigned long long ULL;
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

const char inf = 0x3f;
const int INF = 0x3f3f3f3f;

int test, cas = 1;

int graphY[30][30];
int graphM[30][30];

void floyd(int n, int graph[30][30])
{
    REP(i, 1, n)
    graph[i][i] = 0;

    REP(k, 1, n)
    REP(i, 1, n)
    REP(j, 1, n)
    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

void convert(map<char, int>& indx, map<int, char>& chc, char&u, char&v, int&n)
{
    int& i = indx[u];
    int& j = indx[v];
    if(!i) i = n++, chc[i] = u;
    if(!j) j = n++, chc[j] = v;
    u = i, v = j;
}

int main()
{
#ifdef LOCAL
    freopen("10171.inp", "r", stdin);
#endif // LOCAL

    int m, cost;
    char age, dir, u, v;

    while(scanf("%d", &m) != EOF)
    {
        if(m == 0) break;

        mem(graphY, inf);
        mem(graphM, inf);

        int n = 1;
        map<char, int> indx;
        map<int, char> chc;

        while(m--)
        {
            scanf(" %c %c %c %c %d", &age, &dir, &u, &v, &cost);
            convert(indx, chc, u, v, n);

            if(age == 'Y')
            {
                graphY[u][v] = min(graphY[u][v], cost);
                if(dir == 'B') graphY[v][u] = min(graphY[v][u], cost);
            }
            else
            {
                graphM[u][v] = min(graphM[u][v], cost);
                if(dir == 'B') graphM[v][u] = min(graphM[v][u], cost);
            }
        }

        scanf(" %c %c", &u, &v);
        convert(indx, chc, u, v, n);

        floyd(n, graphY);
        floyd(n, graphM);

        int mn = INT_MAX;
        set<char> place;
        REP(i, 1, n)
        {
            if(graphY[u][i] < INF && graphM[v][i] < INF)
            {
                cost = graphY[u][i] + graphM[v][i];
                if(mn > cost)
                {
                    mn = cost;
                    place.clear();
                    place.insert(chc[i]);
                }
                else if(mn == cost)
                {
                    place.insert(chc[i]);
                }
            }
        }

        if(place.empty())
        {
            puts("You will never meet.");
        }
        else
        {
            printf("%d", mn);
            loop(i, place) printf(" %c", *i);
            putchar('\n');
        }
    }

    return 0;
}
