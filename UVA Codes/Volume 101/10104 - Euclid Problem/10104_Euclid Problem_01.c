#include <stdio.h>

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int c;
    double a,b,d,e,xp,yp,xn,yn,z;

    while(scanf("%lf %lf",&a,&b)!=EOF)
    {
        e = (a>b)?a:b;

        if(a==0 && b == 0)
            printf("1 0 1\n");
        else
        {
            d = gcd(a,b);
            z = a + b;
            c = 1;

            do
            {
                xn = (d - b*c) / z;
                yp = (d + a*c) / z;
                if(xn==(int)xn && yp==(int)yp)
                {
                    printf("%.0lf %.0lf %.0lf\n",xn,yp,d);
                    break;
                }

                xp = (d + b*c) / z;
                yn = (d - a*c) / z;
                if(xp==(int)xp && yn==(int)yn)
                {
                    printf("%.0lf %.0lf %.0lf\n",xp,yn,d);
                    break;
                }

                ++c;
            } while(c<=e);
        }
    }

    return 0;
}
