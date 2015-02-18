#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000

char p[SIZE];
char res[16][160][SIZE];

void crossadd(char *rpt, char *n, char *p, int f)
{
    int i, s,m,tc,ta, a,l;
    l = strlen(n);

    for(i=tc=ta=0; p[i]; ++i)
    {
        m = (p[i]-'0')*f + tc;
        tc = m/10;
        p[i] = m - tc*10 + '0';

        a = (i<l) ? n[i] : 0;
        s = a + p[i] + ta - ('0'<<1);
        ta = s/10;
        rpt[i] = s - ta*10 + '0';
    }

    for(m=tc; m>0; ++i, m=tc)
    {
        tc = m/10;
        p[i] = m - tc*10 + '0';

        a = (i<l) ? n[i] : 0;
        s = a + p[i] + ta - ('0'<<1);
        ta = s/10;
        rpt[i] = s - ta*10 + '0';
    }
    p[i] = '0';
    for(l=i;p[l]=='0';--l) p[l]=0;

    for(s=ta; ta>0; ++i, s=ta)
    {
        ta = s/10;
        rpt[i] = s - ta*10 + '0';
    }
    rpt[i] = '0';
    for(l=i;rpt[l]=='0';--l) rpt[l]=0;

    puts(rpt);
}

void print(char *num)
{
    int i = strlen(num);
    while(i--) putchar(num[i]);
    putchar('\n');
}

int main()
{
    int a, n, i;

    for(a=2; a<3; ++a)
    {
        p[0] = '1';
        p[1] = 0;

        res[a][0][0] = '0';
        res[a][0][1] = 0;

        for(i=1; i<=150; ++i)
            crossadd(res[a][i], res[a][i-1], p, a);
    }

    while(scanf("%d %d",&n,&a)!=EOF && n && a)
        print(res[a][n]);

    return 0;
}
