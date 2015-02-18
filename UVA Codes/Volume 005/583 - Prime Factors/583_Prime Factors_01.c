#include <stdio.h>
#include <string.h>
#include <math.h>

#define IDX(i) (i>>4)
#define SUB(i) ((i&15)>>1)
#define SET(i) prime[IDX(i)] |= (1<<SUB(i))
#define GET(i) (prime[IDX(i)] & (1<<SUB(i)))

#define SIZE 46345

char prime[IDX(SIZE)+1];

void sieve()
{
    memset(prime, 0, sizeof(char));
    prime[0] = 0b10010001;

    register int i,j,l;
    l = sqrt(SIZE);
    for(i=3; i<l; i+=2)
        if(!GET(i))
            for(j=i*i; j<SIZE; j+=i)
                if(j&1) SET(j);
}

int main()
{
    sieve();

    int n, i, l, r;

    while(scanf("%d",&n)!=EOF && n!=0)
    {
        printf("%d =", n);
        if(n<-1) printf(" -1 x"), n=-n;

        while( n>2 && !(n&1))
            printf(" 2 x"), n>>=1;

        if(n>2)
        {
            l = sqrt(n);
            for(i=3; i<=l && n>1; i+=2)
                if(!GET(i))
                    for(r=n/i; n==r*i && r>1; n=r, r=n/i) printf(" %d x", i);
        }

        printf(" %d\n", n);
    }

    return 0;
}
