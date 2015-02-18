#include <stdio.h>
#include <math.h>

int main()
{
    int i,cas,n,res;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        res = 315*n+36962;
        printf("%d\n",abs(res/10-(res/100)*10));
    }
    return 0;
}
