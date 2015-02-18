#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000
#define SQ_SIZE 1000

unsigned char *prime;
unsigned char bit[] =
{
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
    0b01000000,
    0b10000000
};

char isprime(int i)
{
    if(i==2) return 1;
    if(!(1&i)) return 0;
    i >>= 1;
    return !(prime[i>>3] & bit[i&7]);
}
void setpos(int i)
{
    i >>= 1;
    prime[i>>3] |= bit[i&7];
    return;
}

void sieve()
{
    register int lim,sq_siz,i,j;

    lim = SIZE>>3+ 1;
    prime = calloc(lim,sizeof(char));
    prime[0]=0b00000001;

    for(i=3; i <= SQ_SIZE; i+=2)
        if(isprime(i))
            for(j=i*i; j<SIZE; j+=i)
                if(1&j) setpos(j);

    return;
}

int main()
{
    sieve();

    int n,i,j,sum;
    while(scanf("%d",&n)==1)
    {
        for(i=0,sum=0; i<=n; ++i)
            if(isprime(i))
                for(j=n/i; j>0; j/=i) sum+=j;
        printf("%d\n",sum);
    }

    return 0;
}

