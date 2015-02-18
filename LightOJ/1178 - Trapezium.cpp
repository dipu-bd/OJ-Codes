#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int test, cas = 1;

    double a, b, c, d,
           A, B, C, s, ta,
           h, area;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

        A = b, B = fabs(a - c), C = d;
        s = (A + B + C) /  2;
        ta = sqrt(s * (s - A) * (s - B) * (s - C));
        h = 2 * ta / B;
        area = h * (a + c) / 2;

        printf("Case %d: %.8lf\n", cas++, area);
    }

    return 0;
}
