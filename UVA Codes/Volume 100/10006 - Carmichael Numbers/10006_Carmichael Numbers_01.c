#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 65010

#define GET(i) (prime[(i)>>3] & (1<<((i)&7)))
#define isprime(i) (i==2 || ((i&1) && !GET(i>>1)))

char prime[1 + (SIZE >> 4)];

void sieve()
{
    memset(prime, 0, sizeof(char));
    prime[0] = 0b10010001;

    register int i, j, l, s;
    l = (int)sqrt(SIZE) >> 1;
    s = SIZE >> 1;
    for(i = 1; i < l; ++i)
        if(!GET(i))
            for(j = 2 * i * (i + 1); j < s; j += i + i + 1)
                prime[j >> 3] |= (1 << (j & 7));
}

/* power modulus */
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

/* Definition : In number theory, a Carmichael number is a composite positive integer n
 * which satisfies the congruence b^n = b (mod n) where 1 < b < n */
int iscarmical(int n)
{
    if(isprime(n)) return 0;

    int a;
    for(a = 2; a < n; ++a)
        if(pow_mod(a, n, n) != a) return 0;

    return 1;
}

int main()
{
    sieve();

    int n, i = 0;
    for(n = 2; n < SIZE; ++n)
        if(iscarmical(n)) ++i, printf("%d\n", n);
    return i;
}

