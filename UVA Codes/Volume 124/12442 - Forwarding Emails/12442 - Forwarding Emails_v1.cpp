#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define clr(a) memset(a, 0, sizeof(a))

#define MAX 50010
vector<int> graph[MAX];
char check[MAX];
int cnt = 0;

void dfs(int v)
{
    if(check[v] == 1) return;

    ++cnt;
    check[v] = 1;
    vector<int>::iterator i;
    for(i = graph[v].begin(); i != graph[v].end(); ++i) dfs(*i);
    check[v] = 2;
}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        int n, u, v;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
        {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
        }

        clr(check);
        int mc = 0, st = 1;
        for(int i = 1; i <= n; ++i)
        {
            if(!check[i])
            {
                cnt = 0;
                dfs(i);
                if(cnt > mc) mc = cnt, st = i;
            }
        }

        printf("Case %d: %d\n", cas++, st);
        for(int i = 1; i <= n; ++i) graph[i].clear();
    }

    return 0;
}