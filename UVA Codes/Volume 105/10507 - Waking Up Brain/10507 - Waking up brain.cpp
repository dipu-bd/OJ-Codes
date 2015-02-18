#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define CLR(c) memset(c, 0, sizeof(c))

int main()
{
    int year;
    int n, m, id;
    char inp[100];
    int state[50];

    while(scanf("%d %d", &n, &m) == 2)
    {
        id = 1;
        year = 0;
        CLR(state);
        queue<int> nxt;
        map<char, int> sub;
        vector<int> graph[30];

        scanf(" %s", inp);
        for(int i = 0; inp[i]; ++i)
        {
            int& p = sub[inp[i]];
            if(!p)
            {
                p = id++;
                state[p] = 3;
                nxt.push(p);
                nxt.push(0);
            }
        }

        while(m--)
        {
            scanf(" %s", inp);
            int& p = sub[inp[0]];
            if(!p) p = id++;
            int& q = sub[inp[1]];
            if(!q) q = id++;

            graph[p].push_back(q);
            graph[q].push_back(p);
        }

        int vis = 0;
        while(nxt.size())
        {
            int u = nxt.front();
            nxt.pop();
            int d = nxt.front() + 1;
            nxt.pop();

            ++vis;
            vector<int>::iterator it;
            for(it = graph[u].begin(); it != graph[u].end(); ++it)
            {
                int& v = *it;
                state[v]++;
                if(state[v] == 3)
                {
                    nxt.push(v);
                    nxt.push(d);
                    year = d;
                }
            }

            if(vis == n) break;
        }

        if(vis == n) printf("WAKE UP IN, %d, YEARS\n", year);
        else printf("THIS BRAIN NEVER WAKES UP\n");
    }

    return 0;
}
