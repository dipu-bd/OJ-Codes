#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//#define DEBUG_LINE

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

    int getpar(int u)
    {
        if(data[u] == u) return u;
        return data[u] = getpar(data[u]);
    }

    void unify(int u, int v)
    {
        int p = getpar(u);
        int q = getpar(v);
        data[p] = q;
    }

    bool haspath(const int& u, const int& v)
    {
        return (getpar(u) == getpar(v));
    }

    void init()
    {
        for(int i = 0; i < size; ++i) data[i] = i;
    }
};

int main()
{
#ifdef DEBUG_LINE
    freopen("793.txt", "r", stdin);
#endif // DEBUG_LINE

    int test, n;
    int u, v;
    char inp[100];
    int con, dcon;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d ", &n);

        DJSet dj(n + 10);
        con = dcon = 0;
        while(gets(inp) && *inp)
        {
            sscanf(inp + 1, " %d %d", &u, &v);
            if(*inp == 'c') dj.unify(u, v);
            else if(dj.haspath(u, v)) con++;
            else dcon++;
        }

        printf("%d,%d\n", con, dcon);
        if(test) putchar('\n');
    }

    return 0;
}
