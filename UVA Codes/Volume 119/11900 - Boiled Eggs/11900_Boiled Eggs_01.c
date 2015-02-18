#include <stdio.h>

int main()
{
    int t,c,n,p,q,i,s,arr[30];
    scanf("%d",&t);
    for(c=1; c<=t; ++c)
    {
        scanf("%d %d %d",&n,&p,&q);
        for(i=0; i<n; ++i)
            scanf("%d", arr+i);

        i = s = 0;
        do
            s += arr[i++];
        while(s<=q && i<=p && i<=n);

        printf("Case %d: %d\n",c,i-1);
    }

    return 0;
}
