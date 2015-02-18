#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <limits.h>
#include <stdarg.h>
using namespace std;

typedef long long ll;

int m, n;
ll adj[100][100];
ll dis[100][100];

int main()
{
    freopen("matrix.txt", "r", stdin);

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(cin.peek() == ',') cin.get();
            scanf("%lld", adj[i] + j);
        }
    }

    for(int i = 0; i <= m; ++i)
        dis[i][n] = LONG_LONG_MAX;
    for(int i = 0; i <= n; ++i)
        dis[m][i] = LONG_LONG_MAX;

    dis[m][n - 1] = dis[m - 1][n] = 0;
    for(int i = m - 1; i >= 0; --i)
        for(int j = n - 1; j >= 0; --j)
            dis[i][j] = adj[i][j] +
                min(dis[i + 1][j], dis[i][j + 1]);

    printf("%lld\n", dis[0][0]);

    return 0;
}
