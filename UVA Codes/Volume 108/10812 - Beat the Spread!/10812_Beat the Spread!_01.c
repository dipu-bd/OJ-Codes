#include <stdio.h>

int main()
{
    int i,tc;
    long long sum,dif,a,b;
    scanf("%d",&tc);
    for(i=0;i<tc;i++) {
        scanf("%lld %lld",&sum,&dif);
        a=sum+dif;
        b=sum-dif;
        if(a%2 || b%2 || b<0)
            printf("impossible\n");
        else
            printf("%lld %lld\n",a/2,b/2);
    }
    return 0;
}
