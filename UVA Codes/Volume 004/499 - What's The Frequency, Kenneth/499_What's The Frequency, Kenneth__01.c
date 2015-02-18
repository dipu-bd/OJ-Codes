#include <stdio.h>
#include <stdlib.h>

char *list;

int main()
{
    char c;
    register m=0,d;
    list=calloc('z'-'A'+10,sizeof(char));
    while((c=getchar())!=EOF)
    {
        if(c=='\n')
        {
            out(m);
            m=0, free(list);
            list=calloc('z'-'A'+1,sizeof(char));
        }
        else if((c>='A' && c<='Z') || (c>='a' && c<='z'))
        {
            d = ++list[c-'A'];
            if(m<d) m = d;
        }
    }
    return 0;
}

void out(register m)
{
    register i;
    for(i=0; i<='z'-'A';i++)
        if(list[i]==m) putchar(i+'A');
    printf(" %d\n",m);
}
