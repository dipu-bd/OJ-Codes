#include <stdio.h>
#include <iostream>
using namespace std;

int test;
int x1, y1, x2, y2;
int xl, xr, yt, yb;

double liney(double x)
{
    return (y1 - y2) * (x - x1) / (x1 - x2) + y1;
}

double linex(double y)
{
    return (x1 - x2) * (y - y1) / (y1 - y2) + x1;
}

bool line_xrange(double x)
{
    if(x1 <= x2) return x1 <= x && x <= x2;
    else return x2 <= x && x <= x1;
}

bool line_yrange(double y)
{
    if(y1 <= y2) return y1 <= y && y <= y2;
    else return y2 <= y && y <= y1;
}

bool rect_xrange(double x)
{
    return xl <= x && x <= xr;
}

bool rect_yrange(double y)
{
    return yb <= y && y <= yt;
}

bool contains()
{
    //check two end points
    if(rect_xrange(x1) && rect_yrange(y1)) return true;
    if(rect_xrange(x2) && rect_yrange(y2)) return true;

    double x, y;
    //top line
    if(line_yrange(yt))
    {
        x = linex(yt);
        if(line_xrange(x) && rect_xrange(x)) return true;
    }
    //bottom line
    if(line_yrange(yb))
    {
        x = linex(yb);
        if(line_xrange(x) && rect_xrange(x)) return true;
    }
    //left line
    if(line_xrange(xl))
    {
        y = liney(xl);
        if(line_yrange(y) && rect_yrange(y)) return true;

    }
    //right line
    if(line_xrange(xr))
    {
        y = liney(xr);
        if(line_yrange(y) && rect_yrange(y)) return true;
    }

    return false;
}

int main()
{
#ifdef LOCAL
    freopen("191.inp", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d %d %d %d", &xl, &yt, &xr, &yb);

        if(yt < yb) swap(yt, yb);
        if(xr < xl) swap(xl, xr);

        contains() ? puts("T") : puts("F");
    }

    return 0;
}
