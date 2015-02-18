#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#define NODES 20010
#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a));

char visit[NODES];
map<string, int> ind;
vector<int> graph[NODES];

bool hascycle(int u)
{
    if(visit[u]) return (visit[u] == 1);

    visit[u] = 1;

    vector<int>::iterator it;
    for(it = graph[u].begin(); it != graph[u].end(); ++it)
        if(hascycle(*it)) return true;

    visit[u] = 2;
    return false;
}

int main()
{
    int test, cas = 1;

    int m, sz;
    string sa, sb;

    scanf("%d", &test);
    while(test--)
    {
        sz = 1;

        scanf("%d", &m);
        while(m--)
        {
            cin >> sa >> sb;
            int& a = ind[sa];
            int& b = ind[sb];
            if(!a) a = sz++;
            if(!b) b = sz++;
            graph[a].pb(b);
        }

        mem(visit, 0);
        bool cycle = false;
        for(int i = 1; i < sz; ++i)
        {
            if(!visit[i])
            {
                cycle = hascycle(i);
                if(cycle) break;
            }
        }

        printf("Case %d: ", cas++);
        cycle ? puts("No") : puts("Yes");

        ind.clear();
        for(int i = 0; i < sz; ++i) graph[i].clear();
    }

    return 0;
}
