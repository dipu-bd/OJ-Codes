#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int test, cas = 1;

    double r1, r2, r3, H,
           h, p, vol1, vol2;
    const double pi = 2 * acos(0.0);

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf %lf %lf %lf", &r1, &r2, &h, &p);

        H = r1 * h / (r1 - r2);
        r3 = r2 + (r1 - r2) * p / h;
        vol1 = pi * r2 * r2 * (H - h) / 3.0;
        vol2 = pi * r3 * r3 * (H - h + p) / 3.0;

        printf("Case %d: %.10lf\n", cas++, (vol2 - vol1));
    }

    return 0;
}
