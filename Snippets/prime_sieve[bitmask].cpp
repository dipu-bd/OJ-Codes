/* Prime Sieve using BitSet
Approximate Runtime :
    for n = 10 ^ 9 = 1000000000 : 5.340 sec
    for n = 10 ^ 8 = 100000000 : 0.310 sec
    for n = 10 ^ 7 = 10000000 : 0.024 sec
    for n = 10 ^ 6 = 1000000 : 0.002 sec
    for n < 10 ^ 5 < 100000 : 0.000 sec
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SIZE 1000000000

#define GET(i) (prime[(i) >> 3] & (1 << ((i) & 7)))
#define SET(i) (prime[(j) >> 3] |= (1 << ((j) & 7)))
#define isprime(i) (i == 2 || (((i) & 1) && !GET((i) >> 1)))

char prime[1 + (SIZE >> 4)];

void sieve()
{
    int i, j, l, s;

    l = (int)sqrt(SIZE) >> 1;
    s = SIZE >> 1;
    prime[0] = 0b10010001;

    for(i = 1; i < l; ++i)
        if(!GET(i))
            for(j = (i << 1) * (i + 1); j < s; j += i + i + 1)
                SET(j);
}

int main()
{
    time_t a, b;
    a = clock();
    sieve();
    b = clock();
    fprintf(stderr, "RUNTIME : %g\n\n", (double)(b - a) / CLOCKS_PER_SEC);

    fprintf(stderr, "Prime sieve generated.\nSIZE : %d\n\n", SIZE);

    int i, n = 500;
    fprintf(stderr, "Showing prime from 1 to %d: \n", n);
    for(i = 0; i <= n; ++i)
        if(isprime(i)) fprintf(stderr, "%d ", i);

    return 0;
}
