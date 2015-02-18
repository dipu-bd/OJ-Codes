#include <stdio.h>

int main()
{
    char num[]="22233344455566677778889999";

    char inp;
    while((inp=getchar())!=EOF)
    {
        if(inp>='A' && inp<='Z')
            putchar(num[inp-'A']);
        else
            putchar(inp);
    }

    return 0;
}
