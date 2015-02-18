#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <ctype.h>
#include <iterator>
using namespace std;

struct NODE
{
    int u;
    int w;

    NODE() {}
    NODE(int i, int k) : u(i), w(k) { }

    bool operator < (const NODE& rhs) const
    {
        return rhs.w < w;
    }
};

#define MAX 20010
vector<NODE> graph[MAX];
bool visit[MAX];
int dist[MAX];

int main()
{
#ifdef DIPU
    freopen("10986.inp", "r", stdin);
#endif // DIPU

    int test, cas = 1;
    int n, m, s, t;
    int u, v, w;
    priority_queue<NODE> Q;

    cin >> test;
    while(test--)
    {
        scanf("%d %d %d %d", &n, &m, &s, &t);

        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(NODE(v, w));
            graph[v].push_back(NODE(u, w));
        }

        memset(dist, (1 << 7) - 1, sizeof(dist));
        memset(visit, 0, sizeof(visit));

        dist[s] = 0;
        Q.push(NODE(s, w));
        while(Q.size())
        {
            u = Q.top().u;
            Q.pop();

            visit[u] = true;
            if(u == t) break;

            vector<NODE>::iterator it;
            for(it = graph[u].begin(); it != graph[u].end(); ++it)
            {
                v = it->u;
                if(!visit[v])
                {
                    w = dist[u] + it->w;
                    if(dist[v] > w)
                    {
                        dist[v] = w;
                        Q.push(NODE(v, w));
                    }
                }
            }
        }

        printf("Case #%d: ", cas++);
        if(visit[t]) printf("%d\n", dist[t]);
        else printf("unreachable\n");

        while(Q.size()) Q.pop();
        for(int i = 0; i < n; ++i) graph[i].clear();
    }

    return 0;
}