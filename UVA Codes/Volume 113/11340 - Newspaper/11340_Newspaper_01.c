#include <stdio.h>
#include <stdlib.h>


int main()
{
    short *pay;
    unsigned char c;
    int tc,mc,val;
    scanf("%d ",&tc);

    register sum;
    for(;tc>0;tc--)
    {
        pay = calloc(256, sizeof(short));
        scanf(" %d ",&mc);

        for(;mc>0;--mc, pay[c]=val)
            scanf(" %c %d ", &c, &val);

        scanf(" %d ",&mc);
        for(sum=0;mc>0 && (c=getchar())!=EOF;)
            if (c=='\n' || c=='\r') --mc;
            else sum+=(pay[c]);

        printf("%.2f$\n",sum/100.0);
        free(pay);
    }
    return 0;
}
