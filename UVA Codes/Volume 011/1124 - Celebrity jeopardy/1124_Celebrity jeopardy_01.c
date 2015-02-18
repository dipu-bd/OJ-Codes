#include <stdio.h>

int main()
{
    char inp[1000];
    while(scanf(" %[^\n]",inp)==1)
        puts(inp);
    return 0;
}
