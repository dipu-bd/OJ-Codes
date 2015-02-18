#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char *res, *num;
    res=calloc(MAX+10,sizeof(char));
    num=calloc(MAX+10,sizeof(char));
    register i,l,s,t,m=0,out=0;

    while(1)
    {
        gets(num);
        if(num[0]=='0' && num[1]=='\0') break;

        l = strlen(num)-1;
        if(l>m) m=l;
        for(i=MAX,t=0; i>=MAX-m; i--,l--)
        {
            s = (l>=0?num[l]-'0':0) + res[i] + t;
            t = s/10 ;
            res[i] = s-t*10;
        }
        res[i] = t;
        if(t>0) m++;
        out=1;
    }

    if(out) {
        for(i=MAX-m; i<=MAX; i++)
            putchar(res[i]+'0');
        putchar('\n');
    }

    return 0;
}
