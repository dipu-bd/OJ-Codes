#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 1000000
#define SIZE 1010
#define HALF_SIZE 505
#define HALF_SQSIZE 15

char prime[1+(SIZE>>4)];

#define GET(i) ( prime[(i)>>3] & ( 1 << (7&(i)) ))

void sieve()
{
    memset(prime, 0, sizeof(prime));
    prime[0] = 0b10010001;

    int i,j,l;
    for(i=1; i<HALF_SQSIZE; ++i)
        if(!GET(i))
            for(j=2*i*(i+1); j<HALF_SIZE; j+=i+i+1)
                prime[j>>3] |= 1<<(7&j);
    return;
}

int main()
{
    sieve();

    int n, i, j, m, count;

    while(scanf("%d",&n)!=EOF && n)
    {
        printf("%d : ", n);

        count = 0;

        if(!(1&n)) ++count;
        while(!(1&n)) n >>= 1;


        m = sqrt(n);

        for(i=1; i<m; ++i)
            if(!GET(i))
            {
                j = 1 + (i<<1);
                if(!(n%j)) ++count;
                while(!(n%j)) n /= j;
            }

        if(n>1) ++count;

        printf("%d\n", count);
    }

    return 0;
}
