#include <stdio.h>

int main()
{
    int i,j,c,n,a,m;
    scanf("%d",&c);

    for(i=1; i<=c; ++i)
    {
        scanf("%d", &n);

        for(m=j=0; j<n; ++j)
        {
            scanf("%d",&a);
            if(a>m) m = a;
        }

        printf("Case %d: %d\n", i, m);
    }

    return 0;
}
