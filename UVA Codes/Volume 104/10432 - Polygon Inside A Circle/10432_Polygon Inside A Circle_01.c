#include <stdio.h>
#include <math.h>

int main()
{
    double r,n, res;

    while(scanf("%lf %lf",&r,&n)==2)
    {
        res = sin(2.0*acos(-1.0)/n)*r*r*n*0.5;
        printf("%.3lf\n",res);
    }
    return 0;
}
