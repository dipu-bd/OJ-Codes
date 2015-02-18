#include <stdio.h>
#include <math.h>

int main()
{
    double l, h, w, th, v;
    while(scanf("%lf %lf %lf %lf", &l, &w, &h, &th) != EOF)
    {
        if(th == 90.0)
            puts("0.000 mL");

        else
        {
            th = 4 * atan(1) * th / 180.0;

            if(l * tan(th) < h)
            {
                v = w * l * (h - 0.5 * l * tan(th));
            }
            else
            {
                th = 2.0 * atan(1)  - th;
                v = 0.5 * w * h * h * tan(th);
            }

            printf("%.3lf mL\n", v);
        }
    }

    return 0;
}
