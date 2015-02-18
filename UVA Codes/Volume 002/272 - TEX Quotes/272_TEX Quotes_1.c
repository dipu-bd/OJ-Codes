#include <stdio.h>

int main()
{
    int flag=1;
    char inp;
    while((inp=getchar())!=EOF)
    {
        if(inp=='\"')
        {
            if(flag)
            {
                putchar('\`');
                putchar('\`');
                flag=0;
            }
            else
            {
                putchar('\'');
                putchar('\'');
                flag=1;
            }
        }
        else
            putchar(inp);
    }

    return 0;
}
