#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

char *primes;

int main()
{
    sieve();

    int n,c,l,a,b,i,p;
    while(scanf("%d %d",&n,&c)==2)
    {
        printf("%d %d:",n,c);
        l = length(n);

        b = l/2;
        a = l+1 - c - b;
        b += c;

        if(a<1) a=1;
        if(b>l) b=l;

        for(i=1,p=0; i<=n; i++)
            if(!primes[i])
            {
                p++;
                if(p>=a && p<=b) printf(" %d",i);
                else if(p>b) break;
            }

        putchar('\n');
        putchar('\n');
    }

    return 0;
}

void sieve()
{
    register i,j;
    primes = calloc(MAX,sizeof(char));
    for(i=2; i<MAX; i++)
    {
        if(primes[i]) continue;
        for(j=i*2; j<MAX; j+=i) primes[j]=1;
    }
    return;
}

int length(int n)
{
    register len, i;
    for(i=1,len=0; i<=n; i++)
        if(!primes[i]) len++;
    return len;
}
