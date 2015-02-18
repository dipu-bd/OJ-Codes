#include <stdio.h>
#include <stdlib.h>

#define MAX 1000010

int len;
short *primes;
int *factors;
void sieve();

int main()
{
    int n;

    factor_sieve();

    len = 1;
    factors=calloc(MAX, sizeof(int));
    factors[0]=factors[1]=0;

    while(scanf("%d",&n)!=EOF)
    {
        makefactor(n);
        printf("%d\n",factors[n]);
    }
    return 0;
}

void makefactor(int n)
{
    if(len>n) return;
    while(len<=n)
    {
        factors[len] = factors[len-1] +  primes[len];
        len++;
    }
    return;
}

void factor_sieve()
{
    register long long int i,j,l;
    primes=calloc(MAX, sizeof(short));
    for(i=2; i<MAX; i++)
    {
        if(!primes[i]) primes[i]=1;
        for(j=2; j<=i; j++)
        {
            if(primes[j]==1)
            {
                l=i*j;
                if(l>MAX) break;
                primes[l]=1+primes[i];
            }
        }
    }
    return;
}
