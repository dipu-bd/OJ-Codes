#include <stdio.h>

int main()
{
    int h,m;
    float hour, min, res;
    while(scanf("%d:%d",&h,&m)==2)
    {
        if(h==0 && m==0) break;
        hour = 30*h+m/2.0;
        min = 6*m;
        res = (min>hour)? min-hour: hour-min;
        if(res>180) res=360-res;
        printf("%.3lf\n",res);
    }
    return 0;
}
