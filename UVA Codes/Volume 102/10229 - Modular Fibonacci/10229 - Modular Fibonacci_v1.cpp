// C header files
#include <stdio.h>
#include <math.h>

int mask;

#define SIZE 90
long long array[SIZE];

void generate()
{
    array[0] = 0, array[1] = 1;
    for(int n = 2; n < SIZE; ++n)
        array[n] = array[n - 1] + array[n - 2];
}

int fib(int n)
{
    if(n < SIZE)
        return (array[n] & mask);

    long long a, b;

    if(n & 1)
    {
        a = fib(n >> 1);
        b = fib((n >> 1) + 1);
        return mask & (a * a + b * b);
    }
    else
    {
        a = fib(n >> 1);
        b = fib((n >> 1) - 1);
        return mask & (a * ((a + (b << 1))) & mask);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10229.inp", "r", stdin);
#endif

    generate();

    int n, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        mask = (1 << m) - 1;
        printf("%d\n", fib(n));
    }

    return 0;
}
