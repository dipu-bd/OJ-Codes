#include <stdio.h>

int main()
{
    int t,a,b,c;
    register d;

    scanf("%d",&t);
    for(;t>0;t--)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a>b) d=a,a=b,b=d;
        if(a>c) d=a,a=c,c=d;
        if(b>c) d=c,c=b,b=d;

        if(a+b>c) puts("OK");
        else puts("Wrong!!");
    }
    return 0;
}
