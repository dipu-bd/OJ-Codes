#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

struct NODE
{
    int u;
    int v;
    int w;

    NODE() {}
    NODE(int i, int j, int k) : u(i), v(j), w(k) {}

    bool operator < (const NODE& rhs) const
    {
        return rhs.w < w;
    }
};

#define MAX 1010
int maze[MAX][MAX];
int path[MAX][MAX];
bool visit[MAX][MAX];

int main()
{
#ifdef DIPU
    freopen("929.inp", "r", stdin);
#endif // DIPU

    int test;
    int n, m, w;
    priority_queue<NODE> Q;

    cin >> test;
    while(test--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                scanf("%d", maze[i] + j);

        memset(visit, 0, sizeof(visit));
        memset(path, (1 << 7) - 1, sizeof(path));
        while(Q.size()) Q.pop();

        Q.push(NODE(0, 0, maze[0][0]));
        path[0][0] = maze[0][0];

        while(Q.size())
        {
            NODE nod = Q.top();
            Q.pop();

            visit[nod.u][nod.v] = true;
            if(nod.u == n - 1 && nod.v == m - 1) break;

            if(nod.v < m - 1)
            {
                w = nod.w + maze[nod.u][nod.v + 1];
                if(w < path[nod.u][nod.v + 1])
                {
                    path[nod.u][nod.v + 1] = w;
                    Q.push(NODE(nod.u, nod.v + 1, w));
                }
            }

            if(nod.v > 0)
            {
                w = nod.w + maze[nod.u][nod.v - 1];
                if(w < path[nod.u][nod.v - 1])
                {
                    path[nod.u][nod.v - 1] = w;
                    Q.push(NODE(nod.u, nod.v - 1, w));
                }
            }

            if(nod.u < n - 1)
            {
                w = nod.w + maze[nod.u + 1][nod.v ];
                if(w < path[nod.u + 1][nod.v])
                {
                    path[nod.u + 1][nod.v ] = w;
                    Q.push(NODE(nod.u + 1, nod.v, w));
                }
            }

            if(nod.u > 0)
            {
                w = nod.w + maze[nod.u - 1][nod.v];
                if(w < path[nod.u - 1][nod.v])
                {
                    path[nod.u - 1][nod.v ] = w;
                    Q.push(NODE(nod.u - 1, nod.v, w));
                }
            }
        }

        printf("%d\n", path[n - 1][m - 1]);
    }

    return 0;
}