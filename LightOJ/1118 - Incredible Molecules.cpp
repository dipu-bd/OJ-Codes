#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

inline double sqr(const double& x)
{
    return x * x;
}

inline bool istriag(const double& a, const  double& b, const double& c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main()
{
    int test, cas = 1;

    double x1, y1, r1, x2, y2, r2;
    double t, t1, t2, area;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf %lf %lf", &x1, &y1, &r1);
        scanf("%lf %lf %lf", &x2, &y2, &r2);

        t = sqrt(sqr(x1 - x2) + sqr(y1 - y2));

        if(t >= r1 + r2) area = 0.0;
        else if(t == 0 || !istriag(r1, r2, t))
            area = 2 * acos(0.0) * sqr(r1 < r2 ? r1 : r2);
        else
        {
            t1 = acos((sqr(t) + sqr(r1) - sqr(r2)) / (2 * r1 * t));
            t2 = acos((sqr(t) + sqr(r2) - sqr(r1)) / (2 * r2 * t));
            area = r1 * r1 * (t1 - 0.5 * sin(2 * t1)) + r2 * r2 * (t2 - 0.5 * sin(2 * t2));
        }

        printf("Case %d: %.9lf\n", cas++, area);
    }

    return 0;
}
