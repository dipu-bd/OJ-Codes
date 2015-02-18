#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int test, cas = 1;

    int x1, x2, y1, y2, x, y, m;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("Case %d:\n", cas++);

        scanf("%d", &m);
        while(m--)
        {
            scanf("%d %d", &x, &y);
            (x1 < x && x < x2) &&
            (y1 < y && y < y2) ?
            puts("Yes") : puts("No");
        }
    }

    return 0;
}
