#include <stdio.h>

int main()
{
    int tc,n,mp,mn;
    register i,high,low;

    scanf("%d",&tc);
    for(i=1;i<=tc;i++)
    {
        high=low=0;
        scanf("%d",&n);
        scanf("%d",&mp);
        for(n--;n>0;n--,mp=mn)
        {
            scanf("%d",&mn);
            if(mp<mn) high++;
            else if(mp>mn) low++;
        }

        printf("Case %d: %d %d\n",i,high,low);
    }
    return 0;
}
