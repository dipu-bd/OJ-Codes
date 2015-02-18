#include <stdio.h>

int sum(const int);

int main()
{
    int n;
    register int p;
    while(scanf("%d",&n)==1 && n!=0)
        printf("%d\n",sum(n));
    return 0;
}

int sum(const int n)
{
    if(n<10) return n;

    char str[30];
    register int i,r;
    sprintf(str,"%d",n);
    for(i=0,r=0;str[i]!=0;i++)
        r+=str[i]-'0';

    return sum(r);
}
