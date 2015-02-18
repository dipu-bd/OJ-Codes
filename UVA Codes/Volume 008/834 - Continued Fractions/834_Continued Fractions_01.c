#include <stdio.h>

int main()
{
    int a,b,c,i=0;
    while(scanf("%d %d",&a,&b)==2)
    {
        int res[100000];
        for(i=0;b>0;++i)
        {
            c=a/b;
            res[i]=c;
            a=a-b*c;
            c=b;
            b=a;
            a=c;
        }

        for(c=0;c<i;c++)
        {
            if(c==0) printf("[%d;",res[c]);
            else if(c==i-1) printf("%d]\n",res[c]);
            else printf("%d,",res[c]);
        }
    }

    return 0;
}
