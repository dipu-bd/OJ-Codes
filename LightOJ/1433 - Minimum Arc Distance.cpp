#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

inline double hypot(double a, double b)
{
    return sqrt(a * a + b * b);
}

struct point
{
    double x;
    double y;

    point() { }

    friend istream& operator >> (istream& in, point& p)
    {
        in >> p.x >> p.y;
        return in;
    }

    double operator - (const point& b)
    {
        return hypot(x - b.x, y - b.y);
    }
};

int main()
{
    int test, cas = 1;

    point O, A, B;
    double r, theta, arc;
    const double PI = 2 * acos(0.0);

    cin >> test;
    while(test--)
    {
        cin >> O >> A >> B;

        r = O - A;
        theta = 2 * asin(0.5 * (A - B) / r);
        if(theta > PI) theta = 2 * PI - theta;
        arc = r * theta;

        printf("Case %d: %lf\n", cas++, arc);
    }

    return 0;
}
