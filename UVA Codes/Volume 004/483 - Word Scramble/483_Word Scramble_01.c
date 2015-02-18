#include <stdio.h>

int main()
{
    char c,inp[1000],i;
    for(i=0;(c=getchar())!=EOF;)
    {
        if(c!=' '&& c!='\n') inp[i++]=c;
        else while(i>0) putchar(inp[--i]);
        if(c==' '|| c=='\n') putchar(c);
    }
    return 0;
}
