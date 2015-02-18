#include <stdio.h>

int main()
{
    int n,k;
    int i;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        for(i=k;n>=i;i+=k) n++;
        printf("%d\n",n);
    }
    return 0;
}
