#include <stdio.h>

int main()
{
    int a,b;
    register int i,j,lc,k,c,n;
    while(scanf("%d %d",&a,&b)==2)
    {
        lc = 0;
        if(a<b) i=a, j=b;
        else j=a, i=b;

        for(k=i; k<=j; ++k)
        {
            for(n=k,c=1; n>1; ++c)
                if(1&n) n=3*n+1;
                else n>>=1;
            if(c>lc) lc=c;
        }
       
        printf("%d %d %d\n",a,b,lc);
    }
    
    return 0;
}
