#include <stdio.h>
#include <string.h>

#define SIZE 1000000000

char cat[1+(SIZE>>3)];

#define GET(i) (cat[i>>3] & (1<<(i&7)))
#define SET(i) (cat[i>>3] |= (1<<(i&7)))

int main()
{
    int m,n,t,i;
    while(scanf("%d %d",&n,&m)!=EOF && n>0)
    {
        memset(cat,0,sizeof(cat));
        while(n--)
        {
            scanf("%d",&t);
            SET(t);
        }

        for(i=0; m; --m)
        {
            scanf("%d",&t);
            if(GET(t)) ++i;
        }

        printf("%d\n",i);
    }

    return 0;
}
