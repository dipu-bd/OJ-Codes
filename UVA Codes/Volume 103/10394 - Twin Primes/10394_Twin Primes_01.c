#include <stdio.h>
#include <string.h>
#include <math.h>

#define GET(i) (prime[(i)>>3] & (1<<((i)&7)))
#define isprime(i) (i==2 || ((i&1) && !GET(i>>1)))

#define MAX 100001
#define SIZE 18409210

int pos=1;
int twin[MAX];
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
        {
            if(!GET(i-1))
                twin[pos++]=1+(i<<1);

            for(j=2*i*(i+1); j<s; j+=i+i+1)
                prime[j>>3] |= (1<<(j&7));
        }

    for(; i<s && pos<MAX; ++i)
        if(!(GET(i) || GET(i-1)))
            twin[pos++]= 1+(i<<1);
}

int main()
{
    sieve();

    int n;
    while(scanf("%d", &n)!=EOF)
        printf("(%d, %d)\n", twin[n]-2, twin[n]);

    return 0;
}
