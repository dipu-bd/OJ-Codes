#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    int f=0,w=0;
    while((c=tolower(getchar()))!=EOF)
    {
        if(c<'a' || c>'z')
        {
            if(f) w++;
            f=0;
        }
        else f=1;

        if(c=='\n')
        {
            printf("%d\n",w);
            w=0,f=0;
        }
    }
    return 0;
}
