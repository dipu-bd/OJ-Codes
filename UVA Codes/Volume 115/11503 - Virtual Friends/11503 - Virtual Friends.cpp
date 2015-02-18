#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<string, int> people;
int par[100010];
int cnt[100010];

int getpar(const int& v)
{
    if(par[v] == v) return v;
    return par[v] = getpar(par[v]);
}

void join(int u, int v)
{
    int p = getpar(u);
    int q = getpar(v);
    if(p != q)
    {
        par[p] = q;
        cnt[q] = (cnt[p] + cnt[q]);
    }
}


int main()
{
    int test, n, m;
    string na, nb;

    scanf("%d", &test);
    while(test--)
    {
        n = 1;
        par[n] = n;
        cnt[n] = 1;
        people.clear();

        scanf("%d ", &m);
        while(m--)
        {
            cin >> na >> nb;
            int& p = people[na];
            if(!p) p = n++, par[n] = n, cnt[n] = 1;
            int& q = people[nb];
            if(!q) q = n++, par[n] = n, cnt[n] = 1;

            join(p, q);
            printf("%d\n", cnt[getpar(p)]);
        }
    }

    return 0;
}
