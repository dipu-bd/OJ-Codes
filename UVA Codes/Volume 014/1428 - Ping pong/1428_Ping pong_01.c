#include <stdio.h>

int main()
{
    int t,n;
    char inp[150000];
    scanf("%d",&t);
    fflush(stdin);
    for(;t>0;t--)
    {
        gets(inp);
        sscanf(inp,"%d",&n);
        printf("%d\n",n-2);
    }
    return 0;
}
