/* Prime Sieve using BitSet
Approximate Runtime :
    for n = 10 ^ 9 = 1000000000 : 18.715 sec
    for n = 10 ^ 8 = 100000000 : 1.425 sec
    for n = 10 ^ 7 = 10000000 : 0.127 sec
    for n = 10 ^ 6 = 1000000 : 0.012 sec
    for n < 10 ^ 5 < 100000 : 0.000 sec
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <time.h>
using namespace std;

const int SIZE = 10000000;

bitset<32> prime[10 + (SIZE >> 6)];

#define GET(i) prime[i >> 5][i & 31]
#define SET(i) prime[i >> 5].set(i & 31, 1)
#define isprime(i) (i == 2 || ((i & 1) && !GET((i >> 1))))

void sieve()
{
    int i, j, l, s;

    l = (int)sqrt(SIZE) >> 1;
    s = SIZE >> 1;
    prime[0].set(0, 1);

    for(i = 1; i < l; ++i)
        if(!GET(i))
            for(j = (i << 1) * (i + 1);
                    j < s; j += i + i + 1)
                SET(j);
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
        if(isprime(i)) printf("%d ", i);

    return 0;
}
