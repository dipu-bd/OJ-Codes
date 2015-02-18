#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 1000000

#define GET(i) (prime[(i)>>3] & (1<<((i)&7)))
#define isprime(i) (i==2 || ((i&1) && !GET(i>>1)))

char prime[1+(SIZE>>4)];

void sieve()
{
    memset(prime, 0, sizeof(char));
    prime[0] = 0b10010001;

    register int i,j,l,s;
    l = (int)sqrt(SIZE) >> 1;
    s = SIZE >> 1;
    for(i=1; i<l; ++i)
        if(!GET(i))
            for(j=2*i*(i+1); j<s; j+=i+i+1)
                prime[j>>3] |= (1<<(j&7));
}

int main()
{
    sieve();

    int i;
    for(i=0; i<500; ++i)
        if(isprime(i)) printf("%d ",i);

    return 0;
}