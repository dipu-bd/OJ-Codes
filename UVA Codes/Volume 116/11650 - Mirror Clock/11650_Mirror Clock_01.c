#include <stdio.h>
#include <math.h>

int main()
{
    int t,ih,im;
    double h,m,ah,am;

    scanf("%d",&t);
    for(;t>0;t--)
    {
        scanf("%lf:%lf",&h,&m);

        if(h==12) h=0;

        ah = 30*h + m*0.5;
        am = 6*m;

        ah = 360 - ah;
        am = 360 - am;

        im = am/6;
        ih = ah/30;

        if(im==60) im=0;
        if(ih==0) ih=12;

        printf("%.2d:%.2d\n",ih,im);
    }
    return 0;
}
