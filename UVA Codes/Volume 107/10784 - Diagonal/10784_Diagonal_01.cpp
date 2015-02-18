#include <stdio.h>
#include <math.h>

int main()
{
    int c;
    double p;
    for(c=1; scanf("%lf", &p) != EOF && p > 0; ++c)
        printf("Case %d: %.0lf\n", c,
               ceil(0.5 * (3.0 + sqrt(9.0 + 8.0 * p))));

    return 0;
}
