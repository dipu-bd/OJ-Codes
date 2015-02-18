#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int test, cas = 1;

    double r, res;
    const double pi = 2 * acos(0.0);

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf", &r);
        res = (4 - pi) * r * r;
        printf("Case %d: %.2lf\n", cas++, res);
    }

    return 0;
}
