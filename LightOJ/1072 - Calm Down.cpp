#include <stdio.h>
#include <math.h>

int main()
{
    int test, cas = 1;

    double r, R, n, th;
    const double PI = 2.0 * acos(0.0);

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf %lf", &R, &n);
        r = R / (1 + (1 / sin(PI / n)));

        printf("Case %d: %.10lf\n", cas++, r);
    }

    return 0;
}
