#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

double hypot(double x, double y)
{
    return sqrt(x * x + y * y);
}

struct point
{
    int x;
    int y;

    point(int a = 0, int b = 0) : x(a), y(b) { }

    friend istream& operator >> (istream& in, point& p)
    {
        in >> p.x >> p.y;
        return in;
    }

    double operator - (const point& rhs)
    {
        return hypot((double)(x - rhs.x), (double)(y - rhs.y));
    }

    bool operator < (const point& rhs) const
    {
        if(x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

bool long_dist(point la, point lb, point p1, point p2)
{
    double a = (la.y - lb.y);
    double b = (lb.x - la.x);
    double c = -la.x * (la.y - lb.y) + la.y * (la.x - lb.x);
    return (fabs(a * p1.x + b * p1.y + c) == fabs(a * p2.x + b * p2.y + c));
}

int getindx(point a, point b, point c, point d)
{
    double ab = a - b, bc = b - c,
           cd = c - d, ad = d - a,
           ac = a - c, bd = b - d;

    if(long_dist(a, b, d, c))
    {
        if(ab == cd && bc == ad)
        {
            if(ab == bc)
            {
                if(bd == ac) return 0;
                return 2;
            }
            else
            {
                if(bd == ac) return 1;
                return 3;
            }
        }
        return 4;
    }

    return 5;
}


int main()
{
    int test, cas = 1;
    scanf("%d", &test);

    point pt[4];
    while(test--)
    {
        for(int i = 0; i < 4; ++i) cin >> pt[i];

        int mm = 10;
        sort(pt, pt + 4);
        do
        {
            int m = getindx(pt[0], pt[1], pt[3], pt[2]);
            if(m < mm) mm = m;
            if(mm == 0) break;
        }
        while(next_permutation(pt, pt + 4));

        printf("Case %d: ", cas++);

        if(mm == 0) puts("Square");
        else if(mm == 1) puts("Rectangle");
        else if(mm == 2) puts("Rhombus");
        else if(mm == 3) puts("Parallelogram");
        else if(mm == 4) puts("Trapezium");
        else puts("Ordinary Quadrilateral");
    }

    return 0;
}

