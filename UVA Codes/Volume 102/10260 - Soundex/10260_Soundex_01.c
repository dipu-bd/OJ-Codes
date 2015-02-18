#include <stdio.h>

char *code = "01230120022455012623010202";

int main()
{
    char c;
    register d,p=0;
    while((c=getchar())!=EOF)
        if(c>='A' && c<='Z')
        {
            d=code[c-'A'];
            if(d!='0' && d!=p) putchar(d);
            p=d;
        }
        else
        {
            p=0;
            putchar(c);
        }

    return 0;

}
