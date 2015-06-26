#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

char *inp;

int main()
{
    inp = malloc(MAX);

    register i,sl,cl=1,count;
    while(gets(inp) && inp[0]!='.')
    {
        sl=strlen(inp);

        while(cl<=sl)
        {
            for(i=cl,count=1; i<sl; i+=cl)
                if(compare(i,cl)) ++count;
                else break;
            cl=1+i;

        }

        printf("%d\n",count);
        cl = 1;
    }

    return 0;
}

int compare(register j, register count)
{
    register i=0;
    while(i<count)
    {
        if(inp[i]!=inp[j]) return 0;
        else ++i, ++j;
    }
    return 1;
}
