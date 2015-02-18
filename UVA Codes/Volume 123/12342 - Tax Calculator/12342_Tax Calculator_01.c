#include <stdio.h>
#include <math.h>

int main()
{
    int i,t;
    double val,vat;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf",&val);

        val-=180000;
        if(val<1)
        {
            printf("Case %d: 0\n",i);
            continue;
        }

        val -=300000;
        if(val<1)
        {
            val+=300000;
            vat=ceil((val*10)/100);

            if(vat<2000)
                printf("Case %d: 2000\n",i);
            else
                printf("Case %d: %.0lf\n",i,vat);

            continue;
        }

        vat=30000;
        val-=400000;
        if(val<1)
        {
            val=val+400000;
            vat=ceil(vat + (val*15)/100);
            printf("Case %d: %.0lf\n",i,vat);
            continue;
        }

        vat+=60000;
        val-=300000;
        if(val<1)
        {
            val+=300000;
            vat=ceil(vat + (val*20)/100);
            printf("Case %d: %.0lf\n",i,vat);
            continue;
        }

        vat+=60000;
        vat = ceil(vat + (val*25)/100);
        printf("Case %d: %.0lf\n",i,vat);
    }
    return 0;
}
