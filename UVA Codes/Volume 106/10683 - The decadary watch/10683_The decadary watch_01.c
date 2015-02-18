#include <stdio.h>

int main()
{
    int h,m,s,c;
    int T, decadary;
    while(scanf(" %2d%2d%2d%2d",&h,&m,&s,&c)!=EOF)
    {
        T = h*360000 + m*6000 + s*100 + c;
        decadary = 125*T/108;
        printf("%.7d\n", decadary);
    }

    return 0;
}
