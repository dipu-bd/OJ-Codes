#include <stdio.h>
#include <math.h>

int main()
{
    double a,b,c, s,res;
    while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
    {
        s = (a+b+c)*(b+c-a)*(c+a-b)*(a+b-c);
        res = (s>0) ? sqrt(s)/3.0 : -1;
        printf("%.3lf\n",res);

    }
    return 0;
}

