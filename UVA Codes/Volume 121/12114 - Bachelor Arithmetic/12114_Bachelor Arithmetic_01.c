#include <stdio.h>

int main()
{
    int i,b,s;
    double p,q;
    for(i=1; scanf("%d %d",&b,&s) && b; ++i)
    {
        if(b==1) printf("Case %d: :-\\\n",i);
        else
        {
            p = (s>b) ? 1.0: (double)s/b;
            --s, --b;
            q = (s>b) ? 1.0: (double)s/b;

            if(p==q) printf("Case %d: :-|\n",i);
            else if(p>q)printf("Case %d: :-(\n",i);
            else printf("Case %d: :-)\n",i);
        }
    }
    return 0;
}
