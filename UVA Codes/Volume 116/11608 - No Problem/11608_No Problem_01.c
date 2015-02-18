#include <stdio.h>

int p[12];

int main()
{
    int i,c, s,t;
    for(c=1; scanf("%d", &s)!=EOF && s>=0; ++c)
    {
        printf("Case %d:\n", c);

        for(i=1; i<=12; ++i)
            scanf("%d", p+i);

        for(i=p[0]=0; i<12; ++i)
        {
            scanf("%d", &t);
            s += p[i];

            if(s >= t)
            {
              puts("No problem! :D");
              s -= t;
            }
            else puts("No problem. :(");
        }
    }

    return 0;
}
