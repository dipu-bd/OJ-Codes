#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("", "r", stdin);
#endif

    int n, l;
    char inp[500];

    scanf("%d", &n);
    while(n--)
    {
        scanf(" %s", inp);

        l = strlen(inp);
        if(!(strcmp(inp, "1") && strcmp(inp, "4") && strcmp(inp, "78"))) puts("+");
        else
        {
            l = strlen(inp);
            if(l > 1 && inp[l - 1] == '5' && inp[l - 2] == '3') puts("-");
            else if(l > 1 && *inp == '9' && inp[l - 1] == '4') puts("*");
            else if(l > 2 && inp[0] == '1' && inp[1] == '9' && inp[2] == '0') puts("?");
        }
    }
    return 0;
}
