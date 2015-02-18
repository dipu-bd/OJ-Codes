#include <stdio.h>
#include <string.h>

int main()
{
    int p;
    scanf("%d",&p);

    int i,a,b,g;
    for(i=1; i<=p; ++i)
    {
        a = getDecimal();
        b = getDecimal();
        g = GCD(a,b);

        if(g>1) 
            printf("Pair #%d: All you need is love!\n",i);
        else 
            printf("Pair #%d: Love is not all you need!\n",i);
    }
    return 0;
}

char inp[35];
int getDecimal()
{
    scanf(" %[^\n]",inp);
    int l = strlen(inp)-1;
    int d = 0, i = 1;
    while(l>=0)
    {
        if(inp[l]=='1') d |=i;
        --l;
        i <<= 1;
    }
    return d;
}

int GCD(int a, int b)
{
    int m;
    do
    {
        m = a;
        a = b;
        b = m%b;
    }
    while(b>0);
    return a;
}
