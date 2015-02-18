/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
#include <stdio.h>

//result = n * H(n) where H(n) = Harmonic series upto n.

double H[52];

int main()
{
    double h = 0;
    int test, x, i, cas = 1;

    for(i = 1; i <= 100000; ++i)
    {
        h += 1.0 / i;
        if(!(i % 2000)) H[i/2000] = h;
    }

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &x);

        h = H[x / 2000];
        for(i = 2000 * (x / 2000) + 1; i <= x; ++i)
            h += 1.0 / i;

        printf("Case %d: %0.8lf\n", cas++, (x * h));
    }

    return 0;
}
