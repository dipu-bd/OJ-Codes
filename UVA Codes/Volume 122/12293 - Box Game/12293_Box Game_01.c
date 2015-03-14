#include <stdio.h>

int main()
{
    char player[2][20]={"Alice", "Bob"};
    int n;
    while(scanf("%d",&n)==1 && n>0)
    {
        puts(player[!(n & (n + 1))]);
    }
    return 0;
}
