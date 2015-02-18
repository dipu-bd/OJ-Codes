#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 20010
vector<int> graph[MAX];
char color[MAX];

int bfs(int t)
{
    int u, v;
    int col1, col2;
    col1 = col2 = 0;

    queue<int> q;
    q.push(t);
    color[t] = 1;
    while(q.size())
    {
        u = q.front();
        q.pop();

        if(color[u] == 1)
            ++col1, v = 2;
        else
            ++col2, v = 1;

        vector<int>::iterator it;
        for(it = graph[u].begin(); it != graph[u].end(); ++it)
        {
            if(!color[*it])
            {
                color[*it] = v;
                q.push(*it);
            }
        }
    }

    return max(col1, col2);
}

int main()
{
    int test, cas = 1;

    int n, u, v;

    cin >> test;
    while(test--)
    {
        scanf("%d", &n);

        int mv = 0;
        while(n--)
        {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
            if(u > mv) mv = u;
            if(v > mv) mv = v;
        }

        int cnt = 0;
        for(int i = 1; i <= mv; ++i)
            if(graph[i].size() && !color[i])
                cnt += bfs(i);

        printf("Case %d: ", cas++);
        printf("%d\n", cnt);

        memset(color, 0, sizeof(color));
        for(int i = 0; i <= mv; ++i) graph[i].clear();
    }

    return 0;
}
