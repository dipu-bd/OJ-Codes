#include <stdio.h>

int main()
{
    char c;
    register n=0;
    while((c=getchar())!=EOF)
    {
        if(c>='A' && c<='Z')
            for(;n>0;n--) putchar(c);
        else if(c=='*')
            for(;n>0;n--) putchar(c);
        else if(c=='b')
            for(;n>0;n--) putchar(' ');
        else if(c=='!')
            putchar('\n');
        else if(c>='0' && c<='9')
            n+=c-'0';
        else
            putchar(c);
    }
    return 0;
}
