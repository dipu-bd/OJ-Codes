#include <stdio.h>
#include <string.h>

#define MAX 1000

char fact[MAX];
int primes[MAX+1];

void factorial(int);
void cross(int);
void factor(int);
void markSieve();

int main()
{
    markSieve();
    int n;
    register int i,j,l,c;
    while(scanf("%d",&n)==1)
    {
        printf("%d!\n",n);
        factorial(n);
        l=strlen(fact);
        for(i=0,j=l-1;i<l/2;i++,j--)
            c=fact[i],fact[i]=fact[j],fact[j]=c;
        puts(fact);
    }
    return 0;
}

void markSieve()
{
    register int i,j;
    primes[0]=0;
    primes[1]=0;
    for(i=2; i<=MAX; i++)
        primes[i]=1;

    for(i=2; i<=MAX; i++)
    {
        if(!primes[i]) continue;
        for(j=i+i; j<=MAX; j+=i) primes[j]=0;
    }

    return;
}

void factorial(int n)
{
    fact[0]='1';
    fact[1]='\0';
    if(n<2) return;

    register int i;
    for(i=2; i<=n; i++)
        if(primes[i]) cross(i);
        else factor(i);

    return;
}

void factor(int n)
{
    register int i,p;
    for(p=2; n>1; p++)
    {
        if(!primes[p]) continue;
        for(i=n/p; n==i*p ; n=i,i=n/p) cross(p);
    }
    return;
}

void cross(int n)
{
    register int i,a,b,t;
    for(i=0,t=0; fact[i]!='\0'; i++)
    {
        a=fact[i]-'0';
        b=a*n+t;
        t=b/10;
        fact[i]=b-t*10+'0';
    }
    while(t>0)
    {
        b=t;
        t=b/10;
        fact[i++]=b-t*10+'0';
    }
    fact[i]='\0';
    return;
}

