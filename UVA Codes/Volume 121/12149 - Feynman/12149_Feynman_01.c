#include <stdio.h>

int main()
{
    int n;
    register r;
    while(scanf("%d",&n)==1 && n>0) {
        r=(2*n*n*n+3*n*n+n)/6;
        printf("%d\n", r);
    }
    return 0;
}
