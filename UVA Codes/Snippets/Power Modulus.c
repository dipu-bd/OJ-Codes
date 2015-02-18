#include <stdio.h>

long long power(int a, int p)
{
    if(p == 0) return 1;
    if(p & 1)
    {
        long long res = pow(a, (p - 1) >> 1);
        res *= res * a;
        return res;
    }
    else
    {
        long long res = pow(a, p >> 1);
        res *= res;
        return res;
    }
}

int pow_mod(int a, int p, int n)
{
    if(p == 0) return 1;
    if(p & 1)
    {
        long long res = pow_mod(a, (p - 1) >> 1, n);
        res = (res * res * a) % n;
        return res;
    }
    else
    {
        long long res = pow_mod(a, p >> 1, n);
        res = (res * res) % n;
        return res;
    }
}

int main()
{
    int a, p, n;
    long long pow, pmod;

    while(1)
    {
        printf("a = "); scanf("%d", &a);
        printf("p = "); scanf("%d", &p);
        printf("n = "); scanf("%d", &n);

        pow = power(a, p);
        pmod = pow_mod(a, p, n);
        printf("\nPower = %lld\n", pow);
        printf("Power Mod = %d\n\n", pmod);
    }

    return 0;
}

/*input
---------------
2 30 1000
12 3479 100
23820 23989 500
2 100000 10000
2390847 20347938 100000000
*/
