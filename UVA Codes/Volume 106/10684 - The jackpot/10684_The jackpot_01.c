#include <stdio.h>

int main()
{
    int tc,st;
    register max,pre;
    while(scanf("%d",&tc)==1 && tc>0)
    {
        for(max=0,pre=0; tc>0; tc--)
        {
            scanf(" %d",&st);
            if(pre>-st) pre+=st;
            else pre=0;
            if(pre>max) max=pre;
        }
        if(max<=0) puts("Losing streak.");
        else printf("The maximum winning streak is %d.\n",max);
    }
    return 0;
}
