#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

typedef struct
{
    double x;
    double y;
} point;

int main()
{
    point a,b,c,m,o;
    double a1,b1,c1,a2,b2,c2;
    double del,p,l,res;

    while(scanf("%lf %lf %lf %lf %lf %lf", &a.x,&a.y, &b.x,&b.y, &c.x,&c.y)==6)
    {
        m.x = (a.x+b.x)*0.5;
        m.y = (a.y+b.y)*0.5;

        a1 = a.x - b.x;
        b1 = a.y - b.y;
        c1 = -0.5*((a.x*a.x - b.x*b.x) + (a.y*a.y - b.y*b.y));

        a2 = b.x - c.x;
        b2 = b.y - c.y;
        c2 = -0.5*((b.x*b.x - c.x*c.x) + (b.y*b.y - c.y*c.y));

        del = a1*b2 - a2*b1;
        o.x = (b1*c2 - b2*c1)/del;
        o.y = (c1*a2 - c2*a1)/del;

        p = (m.x - o.x)*(m.x - o.x) + (m.y - o.y)*(m.y - o.y);
        l = (m.x - a.x)*(m.x - a.x) + (m.y - a.y)*(m.y - a.y);

        res = 2*PI*sqrt(p+l);

        printf("%.2lf\n",res);
    }

    return 0;
}
