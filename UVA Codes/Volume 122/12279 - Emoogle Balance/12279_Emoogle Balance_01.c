#include <stdio.h>

int main()
{
    int c, t, b;
    register i;
    for(i=1;scanf("%d",&c)==1 && c>0;i++)
    {
        for(b=0;c>0;c--)
        {
            scanf(" %d",&t);
            b += t?1:-1;
        }
        printf("Case %d: %d\n",i,b);
    }
    return 0;
}
