#include <stdio.h>

char inp[30];

int main()
{
    int num;
    while(gets(inp))
    {
        if(inp[1] == 'x')
        {
            sscanf(inp, "%x", &num);
            printf("%d\n", num);
        }
        else
        {
            sscanf(inp, "%d", &num);

            if(num < 0) break;
            printf("0x%X\n", num);
        }
    }

    return 0;
}
