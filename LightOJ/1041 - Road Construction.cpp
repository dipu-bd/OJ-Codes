#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
    Edge() { }
    Edge(int a, int b, int c) : u(a), v(b), w(c) { }

    bool operator < (const Edge& b) const
    {
        return w < b.w;
    }
};

#define MAX 52
int siz;
int par[MAX];
vector<Edge> roads;
map<string, int> ind;

int getpar(int v)
{
    return (v == par[v]) ? v : par[v] = getpar(par[v]);
}

int MST()
{
    int sum = 0;
    int cnt = 2;
    sort(roads.begin(), roads.end());
    for(int i = 0; i <= siz; ++i) par[i] = i;

    for(vector<Edge>::iterator it = roads.begin(); it != roads.end(); ++it)
    {
        int p, q;
        Edge& e = *it;
        p = getpar(e.u);
        q = getpar(e.v);
        if(p != q)
        {
            par[p] = q;
            sum += e.w;
            cnt++;
            if(cnt == siz) return sum;
        }
    }

    return -1;
}
int main()
{
    int test, cas = 1;

    int m, w;
    string a, b;

    cin >> test;
    while(test--)
    {
        siz = 1;
        ind.clear();
        roads.clear();

        cin >> m;
        while(m--)
        {
            cin >> a >> b >> w;
            int& p = ind[a];
            int& q = ind[b];
            if(!p) p = siz++;
            if(!q) q = siz++;
            roads.push_back(Edge(p, q, w));
        }

        printf("Case %d: ", cas++);
        int res = MST();
        if(res < 0) puts("Impossible");
        else printf("%d\n", res);
    }

    return 0;
}
