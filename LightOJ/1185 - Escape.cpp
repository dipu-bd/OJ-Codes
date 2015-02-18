//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//cpp headers
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//typedefs
typedef vector<int> vii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
//useful with graphs

int test, cas = 1;

#define SIZ 105
vii graph[SIZ];
bool vis[SIZ][2];

void dfs(int u, bool run)
{
    if(vis[u][run]) return;
    vis[u][run] = 1;
    loop(v, graph[u]) dfs(*v, !run);
}

int main()
{
    int n, m, u, v;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; ++i) graph[i].clear();

        while(m--)
        {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        clr(vis);
        dfs(1, 0);

        int cnt = 0;
        for(int i = 1; i <= n; ++i) if(vis[i][0]) ++cnt;

        printf("Case %d: %d\n", cas++, cnt);
    }

    return 0;
}
