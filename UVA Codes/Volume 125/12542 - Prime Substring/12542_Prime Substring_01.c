#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 100000

#define INDX(i) (i>>4)
#define SUB(i) ((i&15)>>1)
#define SET(i) prime[INDX(i)] |= (1<<SUB(i))
#define GET(i) (prime[INDX(i)] & (1<<SUB(i)))

#define ISPRIME(i) (i==2 || ((i&1) && !GET(i)))

char prime[INDX(SIZE)+1];
char inp[300];

void makeSieve()
{
    int i, j, t ;

    memset(prime, 0, sizeof(prime));
    prime[0] = 0b10010001;

    t = sqrt(SIZE);
    for(i=3; i<t; i+=2)
        if(!GET(i))
            for(j=i*i; j<SIZE; j+=i)
                if(j&1) SET(j);
}

int main()
{
    /* make sieve */
    makeSieve();


    /* main program */
    int p, i,j, l, m;

    while(scanf(" %[^\n]", inp)!=EOF && !(inp[0]== '0' && !inp[1]))
    {
        l = strlen(inp);
        for(i=m=0; i<l; ++i)
            for(j=0,p=0; (i+j)<l && j<5; ++j)
            {
                p = 10*p + inp[i+j] - '0';
                if(p>m && ISPRIME(p)) m=p;
            }

        printf("%d\n", m);
    }
    return 0;
}
