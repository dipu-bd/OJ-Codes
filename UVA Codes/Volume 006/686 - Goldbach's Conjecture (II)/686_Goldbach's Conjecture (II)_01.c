#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 32768

char bits[] =
{
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
    0b01000000,
    0b10000000,
};

char *primes;

#define INDEX(i) (i>>4)
#define BITP(i) ((i&15) >> 1)
#define GET(i) (primes[INDEX(i)] & bits[BITP(i)])
#define SET(i) (primes[INDEX(i)] |= bits[BITP(i)])


int main()
{
    int i,j,k,n, count;

    /* SIEVE GENERATOR */
    primes = calloc(SIZE, sizeof(char));
    primes[0] = 0b10010001;

    k = sqrt(SIZE);
    for(i=3; i<=k; i+=2)
        if(!GET(i))
            for(j=i*i; j<SIZE; j+=i)
                if(j&1) SET(j);

    /* INPUT AND OUTPUT */
    while(scanf("%d",&n)!=EOF && n>0)
    {
        if(n!=4)
        {
            k = (n>>1);
            count = 0;
            for(i=3; i<=k; i+=2)
                if(!GET(i) && !GET(n-i)) ++count;
        }
        else count=1;
        printf("%d\n", count);
    }

    return 0;
}
