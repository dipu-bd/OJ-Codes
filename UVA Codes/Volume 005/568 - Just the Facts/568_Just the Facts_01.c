#include <stdio.h>

#define MAX 10000

int primes[MAX+1];
char fact[10];

int factorial(int);
void cross(int);
void factor(int);
void markSieve();

int main()
{
    markSieve();

    int n,last;
    while(scanf("%d",&n)==1)
    {
        printf("%5d -> ",n);
        last = factorial(n);
        printf("%d\n",last);
    }
    return 0;
}

int factorial(int n)
{
    if(n<2) return 1;
    register int i;

    fact[0]='1';
    fact[1]='\0';

    for(i=2; i<=n; i++)
        if(primes[i]) cross(i);
        else factor(i);

    for(i=0; fact[i]=='0'; i++);
    return fact[i]-'0';
}

void cross(int n)
{
    register const int m=5;
    register int i,j,a,b,t,c;
    for(i=0,j=0,t=0,c=0; fact[i]!='\0' && c<m; i++)
    {
        a=fact[i]-'0';
        t+=a*n, b=t/10, t-=b*10;
        if(t) c++;
        if(t || c) fact[j++]=t+'0';
        t=b;
    }

    while(t>0 && c<m)
    {
        b=t/10;
        fact[j++]=t-b*10+'0';
        t=b;
    }

    fact[j]='\0';
    return;
}

void markSieve()
{
    register int i,j;

    primes[0]=0;
    primes[1]=0;

    for(i=2; i<=MAX; i++) primes[i]=1;

    for(i=2; i<=MAX; i++)
    {
        if(!primes[i]) continue;
        for(j=i+i; j<=MAX; j+=i) primes[j]=0;
    }

    return;
}

void factor(int n)
{
    register int i,p;
    for(p=2; n>1; p++)
    {
        if(!primes[p]) continue;
        for(i=n/p; n==i*p ; n=i,i=n/p)
            cross(p);
    }
    return;
}
