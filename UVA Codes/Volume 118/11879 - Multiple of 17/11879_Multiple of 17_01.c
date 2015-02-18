#include <stdio.h>
#include <string.h>

const char mods[] = {1,15,4,9,16,2,13}; /* 10^(18*indx) mod 17 */
char num[110];

char ismultiple()
{
    int i,j, l;
    long long n,mod;
    l = strlen(num);
    for(i=l-18, mod=j=0; i>=0; i-=18, ++j)
    {
        sscanf(num+i, "%lld", &n);
        mod += (n%17)*mods[j];
        num[i] = 0;
    }

    if(strlen(num))
    {
        sscanf(num, "%lld", &n);
        mod += (n%17)*mods[j];
    }

    return ((mod%17)==0)+'0';
}

int main()
{
    while(scanf(" %s",num)!=EOF && strcmp(num, "0"))
        printf("%c\n", ismultiple());

    return 0;
}


