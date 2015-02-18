#include <stdio.h>
#include <string.h>

char tmpinp[100];

struct
{
    char name[100];
    double price;
    int rmet;
} last;

char compare(double price, int rmet)
{
    if(last.rmet != rmet)
        return (rmet > last.rmet);
    else return (price < last.price);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10141_Request for Proposal_01.inp","r", stdin);
   // freopen("10141_Request for Proposal_01.out","w", stdout);
#endif

    int i,n,p,rm , fc;
    double price;
    for(fc = 1; scanf("%d %d",&n,&p)!=EOF && n>0; ++fc)
    {
        if(fc>1) putchar('\n');

        last.rmet = 0, last.price = 999999999999999.0;

        /* collect requirement */
        i = n;
        while(i--) scanf(" %[^\n]", tmpinp);

        /* collect proposals */
        for(i=0; i<p; ++i)
        {
            scanf(" %[^\n]", tmpinp);
            scanf("%lf %d", &price, &rm);

            if(compare(price,rm))
            {
                strcpy(last.name, tmpinp);
                last.price = price;
                last.rmet = rm;
            }

            while(rm--) scanf(" %[^\n]", tmpinp);
        }

        /* show result */
        printf("RFP #%d\n%s\n", fc, last.name);
    }

    return 0;
}
