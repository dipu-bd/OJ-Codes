#include <stdio.h>

#define isdgt(i) (i>='0' && i<='9')

int main()
{
    int t;
    scanf("%d",&t);
    fflush(stdin);

    char inp[50];
    register i,c,r;
    for(i=1;i<=t;i++)
    {
        gets(inp);

        if(!isdgt(inp[0])) { i--; continue; }

        c = inp[0]-'0';
        if(isdgt(inp[1]))
            c = c*10 + inp[1]-'0';
        c+= c/2+1 + isdgt(inp[1]);
        r = (inp[c]-'0')*10 + inp[c+1]-'0';
        printf("Case %d: %d\n",i,r);
    }
    return 0;
}

