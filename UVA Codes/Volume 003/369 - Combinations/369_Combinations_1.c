#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

char *prime;
char *fact;
char *comb;

void sieve();
void combination(int, int);
void factorial(int, int, int);
int cross(int);

int main()
{
    sieve();
    int n,m;
    while(scanf("%d %d",&n,&m)==2 && (n>0 || m>0))
        combination(n,m);
    return 0;
}

void sieve()
{
    register i,j;
    prime = calloc(MAX+2,sizeof(char));
    prime[0]=1, prime[1]=1;
    for(i=2; i<=MAX; i++)
    {
        if(prime[i]) continue;
        for(j=i*2; j<=MAX; j+=i)
            prime[j]=1;
    }
    return;
}

void combination(int n, int m)
{
    printf("%d things taken %d at a time is ",n,m);
    if(m>n/2) m=n-m;
    if(m<1) {
        printf("1 exactly.\n");
        return;
    }

    fact=calloc(MAX+2,sizeof(char));
    comb=calloc(128,sizeof(char));
    factorial(n-m+1,n,1);
    factorial(2,m,-1);

    register i,j,l;
    comb[0]='1';
    for(i=2; i<=MAX; i++)
    {
        if(!fact[i]) continue;
        for(j=0; j<fact[i]; j++) l=cross(i);
    }

    for(i=l-1; i>=0; i--)
        putchar(comb[i]);

    printf(" exactly.\n");

    return;
}

void factorial(int start, int end, int p)
{
    register i,j,s,t;
    for(i=start; i<=end; i++)
    {
        if(!prime[i]) fact[i]+=p;
        else
        {
            t=i;
            for(j=2; t>1 && j<i; j++)
            {
                if(prime[j]) continue;
                for(s=t/j; t>1 && t==s*j; t=s, s=t/j) fact[j] += p;
            }
        }
    }
    return;
}

int cross(int n)
{
    register i,a,s,t;
    for(i=0,t=0; comb[i]!='\0'; i++)
    {
        a=comb[i]-'0';
        s=a*n+t;
        t=s/10;
        comb[i]=s-t*10+'0';
    }

    for(s=t/10; t>0; t=s, s=t/10)
        comb[i++] = t-s*10 + '0';

    return i;
}


/*

ime is 1 exactly.

me is 100 exactly.

me is 4950 exactly.

me is 161700 exactly.

me is 3921225 exactly.

me is 75287520 exactly.

me is 1192052400 exactly.

me is 16007560800 exactly.

me is 186087894300 exactly.

me is 1902231808400 exactly.

me is 17310309456440 exactly.

me is 141629804643600 exactly.

me is 1050421051106700 exactly.

me is 7110542499799200 exactly.

me is 44186942677323600 exactly.

me is 253338471349988640 exactly.

me is 1345860629046814650 exactly.

me is 6650134872937201800 exactly.

me is 30664510802988208300 exactly.

me is 132341572939212267400 exactly.

me is 535983370403809682970 exactly.

*/
