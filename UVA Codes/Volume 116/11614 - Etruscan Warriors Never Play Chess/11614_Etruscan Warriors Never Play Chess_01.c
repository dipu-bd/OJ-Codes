#include <stdio.h>
#include <math.h>
int main()
{
    int nc;
    long long int n;
    scanf("%d",&nc);
    for(;nc>0;nc--)
    {
        scanf("%lld",&n);
        printf("%.0lf\n", floor((sqrt(1+8*n) - 1)/2.0));
    }
    return 0;
}
