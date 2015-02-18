#include <stdio.h>
#include <math.h>

int main()
{
    int cn, i;
    double d,v,u,p;

    scanf("%d",&cn);
    for(i=1; i<=cn; i++)
    {
        scanf("%lf %lf %lf",&d,&v,&u);

        if(u <= v || u<=0 || d<=0 || v<=0 )
        {
            printf("Case %d: can't determine\n",i);
        }
        else
        {
            p = d/sqrt(u*u-v*v) - d/u,
            printf("Case %d: %.3lf\n",i,p);
        }
    }

    return 0;
}

