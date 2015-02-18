#include <stdio.h>

int main()
{
    int k, n,m, x,y;
    while(scanf("%d",&k)!=EOF && k>0)
    {
        scanf("%d %d",&n,&m);
        while(k--)
        {
            scanf("%d %d",&x, &y);
            if(x==n || y==m) puts("divisa");
            else if (x>n)
            {
                if (y>m) puts("NE") ;
                else puts("SE");
            }
            else
            {
                if(y>m) puts("NO");
                else puts("SO");
            }
        }
    }

    return 0;
}
