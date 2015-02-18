#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int cas = 1;
    int n, m, q;
    int u, v, w;
    int dist[105][105];
    const int INF = 0x7F7F7F7F;

    while(cin >> n >> m >> q && n)
    {
        //clear dat
        memset(dist, 0x7F, sizeof(dist));
        for(int i = 1; i <= n; ++i) dist[i][i] = 0;

        //take input
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
            dist[u][v] = dist[v][u] = w;
        }

        //floyd-warshall
        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));

        //show res
        if(cas > 1) putchar('\n');
        printf("Case #%d\n", cas++);
        while(q--)
        {
            scanf("%d %d", &u, &v);
            if(dist[u][v] == INF) printf("no path\n");
            else printf("%d\n", dist[u][v]);
        }
    }

    return 0;
}
