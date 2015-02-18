#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <map>
#include <algorithm>
using namespace std;

struct DJSet
{
    int* data;
    int size;

    DJSet(int siz = 10)
    {
        size = siz;
        data = new int[siz];
        init();
    }
    ~DJSet()
    {
        delete data;
    }

    int par(int u)
    {
        if(data[u] == u) return u;
        return data[u] = par(data[u]);
    }

    void unify(int u, int v)
    {
        int p = par(u);
        int q = par(v);
        if(p != q) data[p] = q;
    }

    bool haspath(const int& u, const int& v)
    {
        return (par(u) == par(v));
    }

    void init()
    {
        for(int i = 0; i < size; ++i) data[i] = i;
    }
};


int main()
{
    int test;
    int n, m, u, v;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);

        int* owe =  new int[n + 2];
        DJSet dj(n + 2);
        for(int i = 0; i < n; ++i)
            scanf("%d", owe + i);

        while(m--)
        {
            scanf("%d %d", &u, &v);
            dj.unify(u, v);
        }

        map<int, int> mp;
        map<int, int>::iterator it;
        for(int i = 0; i < n; ++i)
            mp[dj.par(i)] += owe[i];

        bool ispos = true;
        for(it = mp.begin(); ispos && it != mp.end(); ++it)
            if(it->second != 0) ispos = false;

        if(ispos) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }

    return 0;
}
