#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long long int factos[25];

void makeFactorials()
{
    factos[0]=1;
    long long i;
    for(i=1; i<21; ++i)
        factos[i] = factos[i-1] * i;
    return;
}

int compare(void *a, void *b)
{
    return (*(char *)a - *(char *)b);
}

int main()
{
    makeFactorials();
    char s[25];
    int t,n,l,i,j;
    long long p,f;
    scanf("%d",&t);

    while(t--)
    {
        scanf(" %[^\n] %lld",s,&p);
        l = strlen(s);
        qsort(s,l,sizeof(char),compare);

        for(n=l-1;n>=0;--n)
        {
            f = factos[n];
            i = (int)(p/f);
            putchar(s[i]);
            while(i<l) s[i]=s[i+1], ++i;
            p %=f;
        }
        putchar('\n');
    }
    return 0;
}



/*
n elements
array[n]=012345678...
p-th permu
repeat while(n>=0)
{
    n = n-1;
    print array[p/fact(n)];
    p = p % fact(n);
}
*/
