#include <stdio.h>

int main()
{
    long long a;
    while(scanf("%lld",&a)==1)
        printf("%lld\n",3*(a+1)*(a+1)/2-9);
    return 0;
}
