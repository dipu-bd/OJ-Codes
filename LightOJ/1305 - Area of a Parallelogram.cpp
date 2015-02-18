#include <stdio.h>
#include <math.h>

inline double hypot(double a, double b)
{
    return sqrt(a * a + b * b);
}

int main()
{
    int test,  cas = 1;

    double ax, bx, cx, dx;
    double ay, by, cy, dy;
    double a, b, c, s, area;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy);

        dx = ax + cx - bx;
        dy = ay + cy - by;

        a = hypot(cx - bx, cy - by);
        b = hypot(ax - cx, ay - cy);
        c = hypot(ax - bx, ay - by);

        s = (a + b + c) * 0.5;
        area = 2 * sqrt(s * (s - a) * (s - b) * (s - c));

        printf("Case %d: ", cas++);
        printf("%.0lf %.0lf ", dx, dy);
        printf("%.0lf\n", area);
    }

    return 0;
}
