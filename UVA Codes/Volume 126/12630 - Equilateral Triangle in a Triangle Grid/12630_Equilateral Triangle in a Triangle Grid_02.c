#include <stdio.h>

int main()
{
    int n,k,s;
    while(scanf("%d",&n)!=EOF && n>0)
    {
        s = (n*n-1)*(2*n-1)/8;

        printf("%d\n",s);
    }
    return 0;
}
