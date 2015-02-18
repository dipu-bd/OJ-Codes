#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef long long ll;

int A[100005];

int main()
{
    int test, cas = 1;

    double a, b, l, w;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf : %lf", &a, &b);

        l = (200.0 * a) / (a + b);
        w = (200.0 * b) / (a + b);

        printf("Case %d: %.8lf %.8lf\n", cas++, l, w);
    }

    return 0;
}
