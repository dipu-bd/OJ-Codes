#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXN 200000
int ara[MAXN];
int tree[4 * MAXN];

inline int Min(int a, int b)
{
    return a < b ? a : b;
}
inline int Max(int a, int b)
{
    return a > b ? a : b;
}

void build(int start, int stop, int node = 1)
{
    if(start == stop)
    {
        tree[node] = ara[start];
        return;
    }

    int mid = (start + stop) / 2;
    int nn = 2 * node;

    build(start, mid, nn);
    build(mid + 1, stop, nn + 1);
    tree[node] = Min(tree[nn] , tree[nn + 1]);
}

int query(int from, int to, int start, int stop, int node = 1)
{
    if(start >= from && stop <= to)
        return tree[node];

    int mid = (start + stop) / 2;
    int nn = 2 * node;
    int value = INT_MAX;

    if(from <= mid)
        value = query(from, to, start, mid, nn);
    if(to > mid)
        value = Min(value, query(from, to, mid + 1, stop, nn + 1));

    return value;
}

int main()
{
    int len, q, x, y;
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        printf("Case %d:\n", cas++);

        //take array
        scanf("%d %d", &len, &q);
        for(int i = 1; i <= len; ++i)
            scanf("%d", ara + i);

        //build segment tree
        memset(tree, 0, sizeof(tree));
        build(1, len);

        //get queries
        while(q--)
        {
            scanf("%d %d", &x, &y);
            printf("%d\n", query(x, y, 1, len));
        }
    }

    return 0;
}
