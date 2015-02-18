#include <stdio.h>
#include <time.h>

long long fib(int n)        //use BigInt to generate larger numbers
{
    if(n == 0) retursn 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(n == 3) return 2;

    long long a, b;
    if(n & 1)   //if odd
    {
        a = fib(n >> 1);
        b = fib((n >> 1) + 1);
        return (a * a + b * b);
    }
    else    //if even
    {
        a = fib(n >> 1);
        b = fib((n >> 1) - 1);
        return (a * (a + (b << 1)));
    }
}

int main()
{
    print(16);
    test();
    return 0;
}

int print(int n)
{
    printf("List of first %d Fibonacci numbers: \n", n);
    int i;
    for(i = 0; i < n; ++i)
        printf("F[%d] = %lld\n", i, fib(i));

    putchar('\n');
    return 0;
}

int test(void)
{
    printf("Testing Function Speed:\n");

    const int LIMIT = 5000;
    clock_t t1, t2;
    t1 = clock();

    int i, j;
    for(i = 0; i < LIMIT; ++i)
        for(j = 0; j < 90; ++j) fib(j);

    t2 = clock();
    printf("Time to generate first 90 fibonacci %d times: %3d ms\n",
           LIMIT, 1000 * (t2 - t1) / CLOCKS_PER_SEC);
    return 0;
}
