#include <stdio.h>

int main()
{
    int a,b,c;
    register d;

    while(scanf("%d %d %d",&a,&b,&c)==3 && a>0)
    {
        if(a>b) d=a,a=b,b=d;
        if(a>c) d=a,a=c,c=d;
        if(b>c) d=c,c=b,b=d;

        if(a*a+b*b==c*c) puts("right");
        else puts("wrong");
    }
    return 0;
}
