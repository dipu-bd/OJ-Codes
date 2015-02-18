#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 2000

#define INDX(i) (i>>4)
#define SUB(i) ((i&15)>>1)
#define SET(i) prime[INDX(i)] |= (1<<SUB(i))
#define GET(i) (prime[INDX(i)] & (1<<SUB(i)))

#define ISPRIME(i) (i==2 || ((i&1) && !GET(i)))

char prime[INDX(SIZE)+1];
int frq[128];

int main()
{
    char c;
    int i, j, t ;

    /* make sieve */
    memset(prime, 0, sizeof(prime));
    prime[0] = 0b10010001;

    t = sqrt(SIZE);
    for(i=3; i<t; i+=2)
        if(!GET(i))
            for(j=i*i; j<SIZE; j+=i)
                if(j&1) SET(j);

    /* main program */
    scanf("%d ",&t);
    for(j=1; j<=t; ++j)
    {
        memset(frq, 0, sizeof(frq));
        while((c=getchar())!='\n') ++frq[c];

        printf("Case %d: ", j);
        for(i=1, c='0'; c<='z'; ++c)
            if(frq[c]>0 && ISPRIME(frq[c]))
                putchar(c), i=0;

        if(i) puts("empty");
        else putchar('\n');
    }

    return 0;
}
