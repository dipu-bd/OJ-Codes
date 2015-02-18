#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/*
EQ : y = 4x^3 - 2(L+W)x^2 + LWx
1st dy = 12x^2 - 4*(L+W)*x + LW
2nd dy = 24x - 4*(L+W)
*/

double L, W, x;

double getsec(double x)
{
    return 4 * (6 * x - (L + W));
}

void solve(double a, double b, double c)
{
    double d = sqrt(b * b - 4 * a * c);
    double x1 = (-b + d) / (2 * a);
    double x2 = (-b - d) / (2 * a);
    x = (getsec(x1) < getsec(x2)) ? x1 : x2;
}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf %lf", &L, &W);

        solve(12, -4 * (L + W), L * W);
        double vol = x * (L - 2 * x) * (W - 2 * x);

        printf("Case %d: %.8lf\n", cas++, vol);
    }

    return 0;
}
