#include <stdio.h>
#include <math.h>

#define MAX 10000

#define INDX(i) (i>>4)
#define SUB(i) ((i&15)>>1)

char prime[INDX(MAX) + 1];

#define SET(i) prime[INDX(i)] |= 1<<SUB(i)
#define GET(i) (prime[INDX(i)] & (1<<SUB(i)))

void sieve()
{
    memset(prime, 0, sizeof(prime));
    prime[0]= 0b10010001;

    int i,j, l;
    l = sqrt(MAX);
    for(i=3; i<l; i+=2)
        if(!GET(i))
            for(j=i*i; j<MAX; j+=i)
                if(1&j) SET(j);
}

int main()
{
    sieve();

    int m,n,i;
    while(scanf("%d",&m)!=EOF)
        while(m--)
        {
            scanf("%d", &n);
            i = (n+2)>>1;
            i += !(i&1);
            while(GET(i)) i+=2;
            printf("%d\n",i);
        }

    return 0;
}
