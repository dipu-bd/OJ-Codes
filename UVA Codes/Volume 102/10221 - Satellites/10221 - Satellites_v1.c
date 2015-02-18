#include <stdio.h>
#include <math.h>

#define PI (acos(-1))
#define RADIUS (6440.0)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10221.inp", "r", stdin);
#endif

    double s, a, arc, chord;
    char inp[10];

    while(scanf(" %lf %lf %s", &s, &a, inp) != EOF)
    {
        if(inp[0] == 'm') a /= 60.0;
        if(a > 180.0) a = 360.0 - a;	/* what is the arc distance for 240 deg */

        s += RADIUS;
        a = a * PI / 180.0;
        arc = a * s;
        chord = 2 * s * sin(0.5 * a);
        printf("%.6lf %.6lf\n", arc, chord);
    }

    return 0;
}
