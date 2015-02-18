#include <stdio.h>

int main()
{
    int tc,am,fq;
    register i,j;

    scanf("%d",&tc);
    for(; tc>0; tc--)
    {
        scanf(" %d\n%d",&am, &fq);
        for(; fq>0; fq--)
        {
            for(i=1; i<am; i++) {
                for(j=1; j<=i; j++)
                    putchar(i+'0');
                putchar('\n');
            }
            for(; i>0; i--) {
                for(j=1; j<=i; j++)
                    putchar(i+'0');
                putchar('\n');
            }
            if(fq>1) putchar('\n');
        }
        if(tc>1) putchar('\n');
    }
    return 0;
}
