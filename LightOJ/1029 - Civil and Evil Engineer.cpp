#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

struct Edge
{
    int u;
    int v;
    int w;

    bool operator < (const Edge& rhs) const
    {
        return w < rhs.w;
    }
};

int n;
vector<Edge> wires;
int par[150];

int getpar(int v)
{
    return (v == par[v]) ? v : (par[v] = getpar(par[v]));
}

ll MST()
{
    for(int i = 0; i <= n; ++i) par[i] = i;

    ll sum = 0;
    int cnt = 0;
    for(int i = 0, sz = wires.size(); i < sz; ++i)
    {
        Edge& e = wires[i];
        int p = getpar(e.u);
        int q = getpar(e.v);
        if(par[p] != par[q])
        {
            par[p] = q;
            sum += e.w;
            cnt++;
            if(cnt == n) break;
        }
    }

    return sum;
}

int main()
{
    int test, cas = 1;

    cin >> test;
    while(test--)
    {
        Edge e;
        cin >> n;
        while(cin >> e.u >> e.v >> e.w)
        {
            if(!e.w) break;
            wires.push_back(e);
        }

        sort(wires.begin(), wires.end());
        ll res = MST();
        reverse(wires.begin(), wires.end());
        res += MST();

        printf("Case %d: ", cas++);
        if(res & 1) printf("%lld/2\n", res);
        else printf("%lld\n", (res >> 1));

        wires.clear();
    }

    return 0;
}
