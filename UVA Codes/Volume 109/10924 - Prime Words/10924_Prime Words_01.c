#include <stdio.h>
#include <stdlib.h>

#define MAX 1500
char* prime;

void sieve();

int main()
{
    sieve();

    register val;
    char *word = calloc(30, sizeof(char));
    while(scanf("%s",word)!=EOF)
    {
        val = getvalue(word);
        if(!(prime[val]))
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}

void sieve()
{
    prime = calloc(MAX+1, sizeof(char));

    register i,j;
    for(i=2; i<=MAX; i++)
    {
        if(prime[i]) continue;
        for(j=i*2;j<=MAX;j+=i) prime[j]=1;
    }
    return;
}

int getvalue(char *word)
{
    register i,val;
    for(i=0,val=0; word[i]!=0; i++)
    {
        if(word[i]>='A' && word[i]<='Z')
            val += word[i]-'A'+27;
        else if (word[i]>='a' && word[i]<='z')
            val += word[i]-'a'+1;
    }
    return val;
}
