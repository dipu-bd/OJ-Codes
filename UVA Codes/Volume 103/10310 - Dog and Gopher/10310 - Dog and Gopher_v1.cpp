// C header files
#include <stdio.h>
#include <math.h>
// C++ header files
#include <iostream>
// default namespace
using namespace std;

struct Point
{
    double x;
    double y;

    double operator - (Point& rhs)
    {
        return hypot(x - rhs.x, y - rhs.y);
    }
    bool operator == (Point& rhs)
    {
        return (x == rhs.x && y == rhs.y);
    }
};

int main()
{
    int t;
    Point gop, dog, hole;
    bool escape;

    while(scanf("%d",&t)!=EOF)
    {
        scanf("%lf %lf %lf %lf", &gop.x, &gop.y, &dog.x, &dog.y);
        escape = false;

        while(t--)
        {
            scanf(" %lf %lf", &hole.x, &hole.y);
            //printf("[%lf %lf]\n", gop - hole, (dog - hole)*0.5);
            if(escape) continue;
            escape = (gop==hole) || (gop - hole) <= (dog - hole) * 0.5;
            if(escape) printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", hole.x, hole.y);
        }

        if(!escape) puts("The gopher cannot escape.");
    }

    return 0;
}
