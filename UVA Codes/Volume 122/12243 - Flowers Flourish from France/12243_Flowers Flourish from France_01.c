#include <stdio.h>
#include <ctype.h>

int main()
{
    char c,b,i=1,f=0,r=1;
    while((c=getchar())!='*')
    {
        if(isalpha(c))
        {
            if(i) b=tolower(c), i=0;
            if(f) r&=(b==tolower(c)), f=0;
        }
        else
        {
            if(c==' ') f=1;
            if(c=='\n')
            {
                r ? puts("Y"): puts("N");
                r=i=1;
                f=0;
            }
        }
    }
    return 0;
}
