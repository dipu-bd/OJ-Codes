#include <stdio.h>

int main()
{
    int test, cas = 1;
    int m, a, n, r;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &m, &a);
        for(n = 1, r = 0; ; ++n)
        {
            r = (r * 10 + a) % m;
            if(r == 0) break;
        }

        printf("Case %d: %d\n", cas++, n);
    }

    return 0;
}
