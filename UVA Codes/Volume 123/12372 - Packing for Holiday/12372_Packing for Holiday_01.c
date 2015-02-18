#include <stdio.h>

int main()
{
    int i,tc,l,w,h;
    scanf("%d",&tc);
    for(i=1;i<=tc;i++)
    {
        scanf("%d %d %d",&l,&w,&h);
        if(l>20 || w>20 || h>20)
            printf("Case %d: bad\n",i);
        else printf("Case %d: good\n",i);
    }
    return 0;
}
