#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5000

char** fibonacci;
int maximum=1;

void calculate(int last);
char *sum(const char *,const char *);

int main()
{
    fibonacci=calloc(MAX+1,sizeof(char*));
    fibonacci[0]="0", fibonacci[1]="1";

    int inp;
    while(scanf("%d",&inp)==1)
    {
        if (inp>maximum) calculate(inp);
        printf("The Fibonacci number for %d is %s\n",inp,fibonacci[inp]);
    }
    return 0;
}

void calculate(register last)
{
    register i;
    for(i=maximum+1;i<=last;i++)
        fibonacci[i]=sum(fibonacci[i-1],fibonacci[i-2]);
    maximum=last;
}

char *sum(const char *num1,const char *num2)
{
    register la,lb,lm;
    la = strlen(num1);
    lb = strlen(num2);
    lm = (la>lb)?la:lb;
    char *res = calloc(lm+2,sizeof(char));

    register i,a,b,s,t;
    for(i=lm,t=0,--la,--lb;i>=0;--i,--la,--lb)
    {
        a = (la>=0)?num1[la]-'0':0;
        b = (lb>=0)?num2[lb]-'0':0;
        s = a+b+t;
        t = s/10;
        res[i] = s - t*10 + '0';
    }
    for(i=0;res[i]=='0';i++);
    return res+i;
}
