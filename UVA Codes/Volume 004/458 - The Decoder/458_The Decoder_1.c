#include <stdio.h>

int main()
{
    char inp;
    while((inp=getchar())!=EOF)
    {
        if(inp=='\n')
        {
            putchar(inp);
            continue;
        }

        putchar(inp+'*'-'1');
    }

    return 0;
}
