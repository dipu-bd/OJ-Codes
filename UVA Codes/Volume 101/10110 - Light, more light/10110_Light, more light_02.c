#include <stdio.h>

int main()
{
    unsigned int n;
    while(scanf("%ud",&n)!=EOF && n>0)
        if(sqrt(n)==(int)sqrt(n)) puts("yes");
        else puts("no");

    return 0;
}

