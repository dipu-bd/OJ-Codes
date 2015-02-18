#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 1000000

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
    int i,j,k,l,n;

    /* SIEVE GENERATOR */
    primes = calloc(SIZE, sizeof(char));
    primes[0] = 0b10010001;

    l = sqrt(SIZE);
    for(i=3; i<=l; i+=2)
        if(!GET(i))
            for(j=i*i; j<SIZE; j+=i)
               if(j&1) SET(j);

    /* INPUT AND OUTPUT */
    while(scanf("%d",&n)!=EOF && n>0)
    {
        k = (n>>1);
        for(i=3; i<=k; i+=2)
        {
            j=n-i;
            if((i&1) && (j&1))
                if(!(GET(i) || GET(j))) break;
        }
        printf("%d = %d + %d\n",n,i,j);
    }

    return 0;
}
