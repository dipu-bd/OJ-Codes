#include <stdio.h>

void print(char *);

int main()
{
    int t;
    scanf("%d",&t);

    register int i;
    char inp[1000];
    for(i=1;i<=t;i++)
    {
        printf("Case %d: ",i);
        scanf(" %[^\n]",inp);
        print(inp);
    }
    return 0;
}

void print(char *inp)
{
    char c;
    int p,i;
    while(sscanf(inp,"%1c%d%[^\n]",&c,&p,inp)==3)
        for(i=0;i<p;i++) putchar(c);
    for(i=0;i<p;i++) putchar(c);
    putchar('\n');
    return;
}
