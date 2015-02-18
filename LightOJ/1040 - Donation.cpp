#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge
{
    int u, v, w;
    bool operator < (const edge& rhs) const
    {
        return w < rhs.w;
    }
};

vector<edge> v;
int par[60];

int getpar(int v)
{
    if(v == par[v])return v;
    return par[v] = getpar(par[v]);
}

void MST(int n, int& sum)
{
    int cnt = 1;
    for(int i = 0; i <= n; ++i) par[i] = i;

    sort(v.begin(), v.end());
    vector<edge>::iterator it;
    for(it = v.begin(); it != v.end(); ++it)
    {
        edge& e = *it;
        int p = getpar(e.u);
        int q = getpar(e.v);
        if(p != q)
        {
            ++cnt;
            par[p] = q;
            sum -= e.w;
            if(cnt == n) return;
        }
    }

    sum = -1;
}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        int n;
        edge e;
        int sum = 0;

        scanf("%d", &n);
        for(e.u = 1; e.u <= n; ++e.u)
            for(e.v = 1; e.v <= n; ++e.v)
            {
                scanf("%d", &e.w);
                if(e.w > 0)
                {
                    v.push_back(e);
                    sum += e.w;
                }
            }

        if(n > 1) MST(n, sum);
        printf("Case %d: %d\n", cas++, sum);

        v.clear();
    }

    return 0;
}
