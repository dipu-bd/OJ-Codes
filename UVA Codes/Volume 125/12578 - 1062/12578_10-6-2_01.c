#include <stdio.h>

int main()
{
    int tc,h;
    double circ, rect;

    scanf("%d",&tc);
    for(;tc>0;tc--)
    {
        scanf(" %d",&h);
        circ = (h*h/25.0)*3.1415926535;
        rect = h*h*3.0/5.0 - circ;
        printf("%.2lf %.2lf\n", circ, rect);
    }
    return 0;
}
