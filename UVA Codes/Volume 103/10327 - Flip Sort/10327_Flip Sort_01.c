#include <stdio.h>

int inp[1000];

int flip(int len)
{
    register int i,j,num;
    for(i=0,num=0;i<len;i++)
        for(j=i;j<len;j++)
            if(inp[i]>inp[j]) num++;
    return num;
}

int main()
{
    int n;
    register int i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&inp[i]);
        printf("Minimum exchange operations : %d\n",flip(n));
    }
    return 0;
}
