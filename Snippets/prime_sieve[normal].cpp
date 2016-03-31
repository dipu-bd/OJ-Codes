/* Prime Sieve
Approximate Runtime :
    for n = 10 ^ 9 = 1000000000 : 16.100 sec
    for n = 10 ^ 8 = 100000000 : 1.445 sec
    for n = 10 ^ 7 = 10000000 : 0.106 sec
    for n = 10 ^ 6 = 1000000 : 0.007 sec
    for n < 10 ^ 5 < 100000 : 0.000 sec
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SIZE 10000000

char prime[10 + SIZE];

void sieve()
{
    int i, j, l;
    l = (int)sqrt(SIZE);

    prime[0] = prime[1] = 1;
    for(j = 4; j < SIZE; j += 2)
        prime[j] = 1;

    for(i = 3; i <= l; i += 2)
        if(!prime[i])
            for(j = i * i; j < SIZE; j += i + i)
                prime[j] = 1;
}

int main()
{
    time_t a, b;
    a = clock();
    sieve();
    b = clock();
    printf("RUNTIME : %g\n\n", (double)(b - a) / CLOCKS_PER_SEC);

    printf("Prime sieve generated.\nSIZE : %d\n\n", SIZE);

    int i, n = 500;
    printf("Showing prime from 1 to %d: \n", n);
    for(i = 0; i <= n; ++i)
        if(!prime[i]) printf("%d ", i);
    puts("");

    return 0;
}
