#include <stdio.h>

int main()
{
    char *player[]={"Alice", "Bob"};
    int n;
    while(scanf("%d",&n)==1 && n>0)
        puts(player[n%2]);
    return 0;
}
