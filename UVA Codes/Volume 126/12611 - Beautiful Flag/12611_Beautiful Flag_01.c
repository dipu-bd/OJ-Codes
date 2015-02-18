#include <stdio.h>

int main()
{
    int n,r, a,b,c, i;
    scanf("%d",&n);

    for(i=1; i<=n; ++i)
    {
        scanf("%d",&r);
        a = (-9*r) >> 2;
        b = (11*r) >> 2;
        c = (3*r) >> 1;

        printf("Case %d:\n%d %d\n%d %d\n%d %d\n%d %d\n", i, a,c, b,c, b,-c, a,-c);
    }

    return 0;
}
