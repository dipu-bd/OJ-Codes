#include <stdio.h>
#include <math.h>

char isQuirsome(int num, int base)
{
    int a, b;

    a =  num / base;
    b = num - a * base;

    return ((a + b)*( a + b) == num);
}

int powerof10(int a)
{
    if(a) return 10 * powerof10(a-1);
    else return 1;
}

int main()
{
    int n, i, pow, base;
    while(scanf("%d", &n)!=EOF)
    {
        pow = powerof10(n);
        base = sqrt(pow);
        for(i=0; i<pow; ++i)
            if(isQuirsome(i, base))
                printf("%.*d\n", n, i);
    }

    return 0;
}
