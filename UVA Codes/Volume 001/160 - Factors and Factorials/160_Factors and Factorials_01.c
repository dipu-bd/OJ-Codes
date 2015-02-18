#include <stdio.h>

#define MAX 100

int fact[MAX];
int primes[MAX+1];
void markSieve();
void factor(int);

int main()
{
    int n;
    markSieve();
    register int i,c;
    while(scanf("%d",&n)==1 && n>0)
    {
        for(i=0; i<MAX; i++) fact[i]=0;

        printf("%3d! =",n);

        for(i=2; i<=n; i++)
            if(primes[i]) fact[i]++;
            else factor(i);

        for(i=2,c=0; i<=MAX; i++)
        {
            if(!primes[i]) continue;
            if(!fact[i]) break;
            if(c && !(c%15)) printf("\n%6c",' ');
            c++, printf("%3d",fact[i]);
        }
        printf("\n");
    }
    return 0;
}

void factor(int n)
{
    register int i,p;
    for(p=2; n>1; p++)
    {
        if(!primes[p]) continue;
        for(i=n/p; n==i*p ; n=i,i=n/p) fact[p]++;
    }
    return;
}

void markSieve()
{
    register int i,j;
    for(i=0; i<=MAX; i++) primes[i]=1;
    primes[0]=0, primes[1]=0;
    for(i=2; i<=MAX; i++)
    {
        if(!primes[i]) continue;
        for(j=i+i; j<=MAX; j+=i) primes[j]=0;
    }
    return;
}




