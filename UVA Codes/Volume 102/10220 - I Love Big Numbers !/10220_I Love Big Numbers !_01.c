#include <stdio.h>

void cross(int);
int factSum(int);

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",factSum(n));
    return 0;
}

char fact[5000];
int factSum(int n)
{
    register int i,sum;
    fact[0]='1', fact[1]='\0';
    for(i=1; i<=n; i++) cross(i);
    for(i=0,sum=0; fact[i]!='\0'; i++)
        sum+=fact[i]-'0';
    return sum;
}

void cross(int n)
{
    if(n<2) return;
    register int i,a,b,t;
    for(i=0,t=0; fact[i]!='\0'; i++)
    {
        a=fact[i]-'0';
        t+=a*n;
        b=t/10;
        fact[i]=t-b*10+'0';
        t=b;
    }
    while(t>0) {
        b=t/10;
        fact[i++]=t-b*10+'0';
        t=b;
    }
    fact[i]='\0';
    return;
}
