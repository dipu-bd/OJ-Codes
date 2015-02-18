#include <stdio.h>

int main()
{
    int n,data[20];
    int i,a,min,sum;
    while(scanf("%d",&n)==1 && n>0)
    {
        min = getInput();
        data[0] = min;
        for(i=1;i<n;i++)
        {
            a = getInput();
            if(min>a) min = a;
            data[i] = a;
        }

        for(sum=0,i=0;i<n;i++)
            sum += data[i]-min;

        printf("%d\n",sum);
    }
    return 0;
}

int getInput()
{
    char c;
    int i,b;
    for(i=0,b=0;i<25;i++)
    {
        c = getchar();
        if(c==' ') b++;
        else if(c!='X') i--;
    }
    return b;
}
