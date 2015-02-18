#include <stdio.h>

#define MAX 1000000
char *num1,*num2;

int main()
{
    int m,n;
    register int i,j,a,b,t,s;
    register char c;
    num1=calloc(MAX, sizeof(char));
    num2=calloc(MAX, sizeof(char));

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf(" %d",&m);
        for(j=0,t=0; j<m;)
        {
            c=getchar();
            if(c>='0' && c<='9')
            {
                if(t) num1[j++]=c, t=0;
                else num2[j]=c, t=1;
            }
        }

        for(j--,t=0; j>=0; j--)
        {
            a=num1[j]-'0';
            b=num2[j]-'0';
            s=a+b+t;
            t=s/10;
            num1[j]=(s-t*10)+'0';
        }
        num1[m]=0;

        puts(num1);
        if(i!=n-1) putchar('\n');
    }

    return 0;
}
