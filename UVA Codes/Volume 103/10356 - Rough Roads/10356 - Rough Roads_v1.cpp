#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

#define PII pair<int, int>
#define mp make_pair
#define pb push_back
#define _a first
#define _b second
typedef vector<PII>::iterator VII;

struct Node
{
    int v;
    int w;
    bool ec;

    Node() { }
    Node(const int& u, const int& c, const int& even = true) : v(u), w(c), ec(even) { }

    bool operator < (const Node& rhs) const
    {
        if(w == rhs.w) return rhs.ec < ec;
        return rhs.w < w;
    }
};

#define SIZE 510
vector<PII> graph[SIZE];
int dist[SIZE][2];

void dijkstra(int n)
{
    memset(dist, (1 << 7) - 1, sizeof(dist));

    priority_queue<Node> pq;
    pq.push(Node(0, 0, 0));
    dist[0][0] = 0;

    while(pq.size())
    {
        Node nod = pq.top();
        pq.pop();

        //printf("%d %d %d\n", nod.v, nod.w, nod.ec);

        int& u = nod.v;
        if(u == n - 1 && !nod.ec)
        {
            printf("%d\n", nod.w);
            return;
        }

        int sin = nod.ec ? 0 : 1;
        for(VII it = graph[u].begin(); it != graph[u].end(); ++it)
        {
            int& v = it->_a;
            int w = nod.w + it->_b;
            if(w < dist[v][sin])
            {
                dist[v][sin] = w;
                pq.push(Node(v, w, !nod.ec));
            }
        }
    }

    puts("?");
}

int main()
{
#ifdef DIPU
    //freopen("10356.inp", "r", stdin);
#endif // DIPU

    int cas = 1, n, r, u, v, w;

    while(scanf("%d %d", &n, &r) == 2)
    {
        while(r--)
        {
            scanf("%d %d %d", &u, &v, &w);
            if(u < n && v < n)
            {
                graph[u].pb(mp(v, w));
                graph[v].pb(mp(u, w));
            }
        }

        printf("Set #%d\n", cas++);
        dijkstra(n);

        for(int i = 0; i < n; ++i) graph[i].clear();
    }

    return 0;
}


/*
5 5
0 1 10
0 2 60
1 2 10
2 3 10
0 4 10
*/