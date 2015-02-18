#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int n;
    while(scanf("%ud",&n)!=EOF && n>0)
        if(sqrt(n)==ceil(sqrt(n))) puts("yes");
        else puts("no");

    return 0;
}
