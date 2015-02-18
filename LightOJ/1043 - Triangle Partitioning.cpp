#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int test, cas = 1;

    double a, b, c, x, H,
           B, sa, ta, ar, ad;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf %lf %lf %lf", &c, &b, &a, &x);

        sa = (a + b + c) / 2;
        ar = sqrt(sa * (sa - a) * (sa - b) * (sa - c));
        ta = ar / (1 + x);
        sa = ta * x;
        H = 2 * ar / a;

        B = c * H * (2 * (sa + ta) - a * H);
        ad = -B + sqrt(B * B + 8 * a * sa * c * c * H * H * H) / (2 * a * H * H);

        printf("Case %d: %.8lf\n", cas++, ad);
    }

    return 0;
}

