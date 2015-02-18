#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 46345
#define GET(i) (prime[(i)>>3] & (1<<((i)&7)))

char prime[1+(SIZE>>4)];

void sieve()
{
    memset(prime, 0, sizeof(char));
    prime[0] =  0b10010001;

    int i,j,l,s;
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

    int n, i,j, l, r;
    while(scanf("%d",&n)!=EOF && n!=0)
    {
        printf("%d =", n);
        if(n<-1) printf(" -1 x"), n=-n;

        while(n>2 && !(n&1))
            printf(" 2 x"), n>>=1;

        if(n>2)
        {
            l = (1+(int)sqrt(n)) >> 1;
            for(i=1; i<=l && n>1; ++i)
                if(!GET(i))
                {
                    j = 1 + (i<<1);
                    for(r=n/j; n==r*j && r>1; n=r,r=n/j)
                        printf(" %d x", j);
                }
        }

        printf(" %d\n", n);
    }

    return 0;
}
