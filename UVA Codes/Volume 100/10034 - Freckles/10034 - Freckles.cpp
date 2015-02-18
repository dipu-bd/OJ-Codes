#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge
{
    int u;
    int v;
    double w;

    Edge() { }
    Edge(int ua, int va, double wa) : u(ua), v(va), w(wa) { }

    bool operator < (const Edge& b) const
    {
        return w < b.w;
    }
};

inline double sqr(const double& s)
{
    return s * s;
}

inline double getdist(double* a, double* b)
{
    return sqrt(sqr(a[0] - b[0]) + sqr(a[1] - b[1]));
}

int par[110];

void init(int n)
{
    for(int i = 0; i <= n; ++i) par[i] = i;
}

int getpar(int& v)
{
    if(par[v] == v) return v;
    return par[v] = getpar(par[v]);
}

bool unify(int u, int v)
{
    int p = getpar(u);
    int q = getpar(v);
    if(p == q) return false;

    par[p] = q;
    return true;
}


int main()
{
    int test, n;
    double point[110][2];

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%lf %lf", point[i], point[i] + 1);

        vector<Edge> ve;
        vector<Edge>::iterator it;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                ve.push_back(Edge(i, j, getdist(point[i], point[j])));

        init(n);
        int cnt = 0;
        double dist = 0;
        sort(ve.begin(), ve.end());
        for(it = ve.begin(); it != ve.end(); ++it)
        {
            if(unify(it->u, it->v))
            {
                cnt++;
                dist += it->w;
                if(cnt == n - 1) break;
            }
        }

        printf("%.2lf\n", dist);
        if(test) putchar('\n');
    }

    return 0;
}


