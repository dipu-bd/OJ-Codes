#include <stdio.h>

int main()
{
    int h,m,s;
    int t,tt,ic;
    double v,tv,r,tr;
    char inp[50];

    for(ic=0,tr=0;scanf(" %[^\n]",inp)==1;)
    {
        if(inp[8]==' ')
        {
            sscanf(inp,"%d:%d:%d %lf",&h,&m,&s,&tv);
            tt = h*3600 + m*60 + s;
            if(ic) tr += v * (tt-t) / 3600.0;
            else ic=1; t=tt, v = tv;
        }
        else
        {
            sscanf(inp,"%d:%d:%d",&h,&m,&s);
            tt =  h*3600 + m*60 + s;
            r = v * (tt-t) / 3600.0;
            printf("%s %.2lf km\n",inp,tr+r);
        }
    }
    return 0;
}
