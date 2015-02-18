#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 65010
char prime[SIZE >> 4];

#define GET(i) (prime[(i)>>3] & (1 << ((i) & 7)))
#define isprime(i) ((i)==2 || ( ((i)&1) && !GET((i)>>1) ) )

void sieve()
{
    prime[0] = 0b10010001;

    int i, j, l, m;
    l = (int)sqrt(SIZE) >> 1;
    m = SIZE >> 1;

    for(i = 1; i < l; ++i)
        if(!GET(i))
            for(j = (i << 1) * (i + 1); j < m; j += i + i + 1)
                prime[j >> 3] |= (1 << (j & 7));

    return;
}

/* Theorem (A. Korselt 1899): A positive composite integer n is a Carmichael number
 * if and only if n is square-free (no prime divisior can occur more than once),
 * and for all prime divisors p of n, it is true that (p - 1) | (n - 1) (where a | b means that a divides b). */
int iscarmichael(int n)
{
    if(isprime(n)) return 0;

    int l, p;
    l = n - 1;
    if(!(n & 1)) n >>= 1;
    if(!(n & 1)) return 0;  // if not square free return false;

    for(p = 3; n > 1 && p < SIZE; p += 2)
        if(!GET(p>>1))
        {
            if(!(n % p))                    // if (p | n) or p is a divisor.
            {
                n /= p;
                if(l % (p - 1)) return 0;   // if (p-1) | (n-1) return false;
            }
            if(n>1 && !(n % p)) return 0;   // if not square free return false;
        }

    return 1;       // at this point n is either <2 or a prime : anyway true.
}

int main()
{
    sieve();

    int n;
    for(n = 2; n < SIZE; ++n)
        if(iscarmichael(n))
            printf("%d\n", n);

    return 0;
}
