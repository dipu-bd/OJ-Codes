#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int test, cas = 1;

    long a, b, res;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lld %lld", &a, &b);
        res = (2 * b / 3) - (2 * (a - 1) / 3);
        printf("Case %d: %lld\n", cas++, res);
    }

    return 0;
}
