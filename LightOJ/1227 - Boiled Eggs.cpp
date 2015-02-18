#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int test, cas = 1;

    int n, p, q, s, x, cnt;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d", &n, &p, &q);

        s = 0, cnt = 0;
        while(n--)
        {
            scanf("%d", &x);
            if(s + x <= q &&
                    cnt + 1 <= p)
                cnt++, s += x;
        }

        printf("Case %d: %d\n", cas++, cnt);
    }

    return 0;
}
