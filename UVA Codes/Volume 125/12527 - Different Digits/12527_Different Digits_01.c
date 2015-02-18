#include <stdio.h>
#include <stdlib.h>

char *num;
int isRepeated(int);

int main()
{
    int low, high;
    register i,c;
    while(scanf("%d %d",&low,&high)==2)
    {
        for(i=low,c=0;i<=high;i++)
            if(isRepeated(i)) c++;
        printf("%d\n",c);
    }
    return 0;
}

int isRepeated(int n)
{
    num = calloc(10,sizeof(char));

    register s,t;
    for(s=n/10;n>0;n=s, s=n/10)
    {
        t=n-s*10;
        if(num[t]) return 0;
        num[t]=1;
    }

    return 1;
}
