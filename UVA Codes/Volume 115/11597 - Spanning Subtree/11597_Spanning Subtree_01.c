#include <stdio.h>

int main()
{
    int n,i=1;
    while(scanf("%d",&n)==1 && n>0)
        printf("Case %d: %d\n",i++, n>>1);

    return 0;
}
