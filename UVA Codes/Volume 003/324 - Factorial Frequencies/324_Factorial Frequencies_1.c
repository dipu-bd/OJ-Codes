#include <stdio.h>

#define MAX 366

int primes[MAX+1];
int res[10];
char fact[800];

void factorial(int);
void cross(int);
void factor(int);
void markSieve();

int main()
{
    markSieve();
    int n;
    register int i;
    while(scanf("%d",&n)==1 && n>0)
    {
        factorial(n);
        for(i=0; i<10; i++) res[i]=0;
        for(i=0; fact[i]!='\0'; i++) res[fact[i]-'0']++;

        printf("%d! --",n);
        printf("\n   (0)%5d",res[0]);
        for(i=1; i<5; i++) printf("%5c%d)%5d",'(',i,res[i]);
        printf("\n   (5)%5d",res[5]);
        for(i=6; i<10; i++) printf("%5c%d)%5d",'(',i,res[i]);
        printf("\n");
    }
    return 0;
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

void cross(int n)
{
    register int i,a,b,t;
    for(i=0,t=0; fact[i]!='\0'; i++)
    {
        a=fact[i]-'0';
        t+=a*n, b=t/10, t-=b*10;
        fact[i]=t+'0';
        t=b;
    }

    while(t>0)
    {
        b=t/10;
        fact[i++]=t-b*10+'0';
        t=b;
    }
    fact[i]='\0';
    return;
}

void markSieve()
{
    register int i,j;
    for(i=0; i<=MAX; i++)
        primes[i]=1;

    primes[0]=0;
    primes[1]=0;

    for(i=2; i<=MAX; i++)
    {
        if(!primes[i]) continue;
        for(j=2; (j*i)<=MAX; j++)
            primes[j*i]=0;
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

