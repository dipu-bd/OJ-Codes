#include <stdio.h>

int dgsqsum(int n)
{
    int s, m, t;
    for(s=0, t=n/10; n>0; n=t, t=n/10)
    {
        m = (n - t*10);
        s += m*m;
    }
    return s;

}

int main()
{
    int t,n,i,m;
    scanf("%d",&t);
    for(i=1; i<=t; ++i)
    {
        scanf("%d",&n);
        m = dgsqsum(n);
        while(!(m==1 || m==4)) m=dgsqsum(m);

        if(m==1) printf("Case #%d: %d is a Happy number.\n", i, n);
        else printf("Case #%d: %d is an Unhappy number.\n", i, n);
    }

    return 0;
}
