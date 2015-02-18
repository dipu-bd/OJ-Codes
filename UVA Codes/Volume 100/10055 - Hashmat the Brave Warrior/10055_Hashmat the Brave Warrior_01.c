#include <stdio.h>
#include <math.h>

int main()
{
    long long int a,b;
    while(scanf("%lld %lld", &a, &b)==2)
        printf("%lld\n", abs(a-b));

    return 0;
}
