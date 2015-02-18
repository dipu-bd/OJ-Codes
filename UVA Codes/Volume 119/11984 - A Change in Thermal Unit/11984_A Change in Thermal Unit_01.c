#include <stdio.h>

int main()
{
    int n,c,d;
    scanf("%d",&n);

    register int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&c,&d);
        printf("Case %d: %.2lf\n",i,c+d*(5.0/9.0));
    }
    return 0;
}
