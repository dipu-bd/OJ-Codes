#include <stdio.h>
#include <string.h>

int main()
{
    int n,i,j,k,l;
    char inp[150];
    while(scanf("%d",&n)==1)
    {
        if(n==0) return 0;
        scanf(" %s",inp);
        l=strlen(inp);
        n=l/n;
        for(i=0; i<l; i+=n)
            for(j=i+n-1; j>=i; j--)
                putchar(inp[j]);

        putchar('\n');
    }
    return 0;
}
