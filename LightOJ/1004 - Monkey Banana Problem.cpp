#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 210
typedef long long ll;

int siz, dsiz;
ll graph[MAX][MAX];
ll save[MAX][MAX];

inline int len(int i)
{
    return abs(2 * (i / siz) * siz - i);
}

inline ll max(ll a, ll b)
{
    return (a > b) ? a : b;
}

ll getmax(int x, int y)
{
    if(x == dsiz) return graph[x][y];
    if(save[x][y] > 0) return save[x][y];

    save[x][y] = graph[x][y];
    if(x < siz)
        save[x][y] += max(getmax(x + 1, y), getmax(x + 1, y + 1));
    else
    {
        if(y == 1)
            save[x][y] += getmax(x + 1, y);
        else if(y == len(x))
            save[x][y] += getmax(x + 1, y - 1);
        else
            save[x][y] += max(getmax(x + 1, y), getmax(x + 1, y - 1));
    }

    return save[x][y];
}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &siz);
        dsiz = 2 * siz - 1;
        for(int i = 1; i <= dsiz; ++i)
            for(int j = 1, l = len(i); j <= l; ++j)
                scanf("%lld", graph[i] + j);

        memset(save, 0, sizeof(save));
        ll res = getmax(1, 1);
        printf("Case %d: %lld\n", cas++, res);
    }

    return 0;
}
