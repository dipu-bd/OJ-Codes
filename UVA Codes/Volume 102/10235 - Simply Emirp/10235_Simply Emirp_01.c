#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 1000000

#define INDEX(i) (i>>4)
#define SUB(i) ((i&15)>>1)
#define GET(i) (prime[INDEX(i)] & (1<<SUB(i)))
#define SET(i) prime[INDEX(i)] |= 1<<SUB(i)
#define ISPRIME(i) (i==2 || ((i&1) && !GET(i)))

char prime[INDEX(SIZE)+2];

void sieve()
{
    memset(prime, 0, sizeof(prime));
    prime[0] = 0b10010001;

    int i,j, l;
    l = sqrt(SIZE);
    for(i=3; i<l; i+=2)
        if(!GET(i))
            for(j=i*i; j<SIZE; j+=i)
                if(1&j) SET(j);

}

int main()
{
    sieve();
    int n, r, i,j;
    while(scanf("%d", &n)!=EOF)
    {
        for(r=0,i=n,j=i/10; i ; i=j, j=i/10)
            r = r*10 + (i - j*10);

        if(!ISPRIME(n)) printf("%d is not prime.\n",n);
        else if(n!=r && ISPRIME(r)) printf("%d is emirp.\n", n);
        else printf("%d is prime.\n", n);
    }

    return 0;
}
