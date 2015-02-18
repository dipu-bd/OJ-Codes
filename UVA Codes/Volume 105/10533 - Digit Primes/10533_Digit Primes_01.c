#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 1000001

#define GET(i) (prime[(i)>>4] & (1<<(((i)&15)>>1)))
#define isprime(i) (i==2 || ((i&1) && !GET(i)))
#define SUM(n) (n - 9 * (n/10 + n/100 + n/1000 + n/10000 + n/100000))

int count[SIZE];
char prime[1+(SIZE>>4)];

void sieve()
{
    memset(prime, 0, sizeof(char));
    prime[0] =  0b10010001;

    int i,j,l,s;
    l = (int)sqrt(SIZE) >> 1;
    s = SIZE >> 1;
    for(i=1; i<l; ++i)
        if(!(prime[i>>3] & (1<<(i&7))))
            for(j=2*i*(i+1); j<s; j+=i+i+1)
                prime[j>>3] |= (1<<(j&7));
}

void check()
{
    count[0] = 0;
    int i;
    for(i=1; i<SIZE; ++i)
        count[i] = (isprime(i) && isprime(SUM(i))) ? count[i-1] + 1 : count[i-1];

}

int main()
{
    sieve();
    check();

    int n, t1, t2;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &t1, &t2);
        printf("%d\n", count[t2] - count[t1-1] );
    }

    return 0;
}
