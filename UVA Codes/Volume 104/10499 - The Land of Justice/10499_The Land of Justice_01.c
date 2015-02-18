#include <stdio.h>

int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF && n>=0)
        if(n==1) puts("0%");
        else printf("%.0lf%%\n", 25.0*n);

    return 0;
}
