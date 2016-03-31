/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 ===================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <set>
using namespace std;

int test, cas = 1;

int n;
char inp[2006];
short mat[2006][2006];

struct range
{
    int l, r;
    range(int x, int y) : l(x), r(y) { }

    bool operator < (const range& p) const
    {
        if(r - l == p.r - p.l)
        {
            int x = mat[l][p.l];
            if(l + x <= r && p.l + x <= p.r)
                return inp[l + x] < inp[p.l + x];
            return false;
        }
        return (r - l) < (p.r - p.l);
    }
};

void build()
{
    n = strlen(inp + 1);

    // build compare matrix
    for(int i = n; i >= 1; --i)
    {
        for(int j = n; j >= 1; --j)
        {
            if(inp[i] == inp[j])
                mat[i][j] = mat[i + 1][j + 1] + 1;
            else
                mat[i][j] = 0;
        }
    }
}

set<range> all;
int getsubcount(int l, int r)
{
    all.clear();
    for(int i = l; i <= r; ++i)
        for(int j = i; j <= r; ++j)
            all.insert(range(i, j));
    return all.size();
}

int main()
{
    int q, l, r;

    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", inp + 1);

        build();

        scanf("%d", &q);
        while(q--)
        {
            scanf("%d %d", &l, &r);
            printf("%d\n", getsubcount(l, r));
        }
    }

    return 0;
}


