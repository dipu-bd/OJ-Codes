#include <stdio.h>
#include <string.h>

int array[1000][1000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11992.inp","r", stdin);
    #endif

    int r, c, m, n;
    int x1, y1, x2, y2, v;
    int sum, max, min, i, j, k;

    while(scanf("%d %d %d", &r, &c, &m) != EOF)
    {
        memset(array, 0, sizeof(array));
        while(m--)
        {
            scanf("%d", &n);

            if(n == 1)
            {
                scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &v);
                for(i = x1 - 1; i < x2; i++)
                    for(j = y1 - 1; j < y2; j++)
                        array[i][j] += v;
            }
            else if(n == 2)
            {
                scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &v);
                for(i = x1 - 1; i < x2; i++)
                    for(j = y1 - 1; j < y2; j++)
                        array[i][j] = v;
            }
            else if(n == 3)
            {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                sum = 0, max = 0, min = array[x1 - 1][y1 - 1];

                for(i = x1 - 1; i < x2; i++)
                    for(j = y1 - 1; j < y2; j++)
                    {
                        v = array[i][j];
                        if(v > max) max = v;
                        if(v < min) min = v;
                        sum += v;
                    }
                printf("%d %d %d\n", sum, min, max);
            }
        }
    }

    return 0;
}
