#include <stdio.h>

int main()
{
    int n,k,s;
    while(scanf("%d",&n)!=EOF && n>0)
    {
        if(n==1) s = 1;
        else if(n==2) s = 1;
        else if(n==3) s = 5;
        else s =  (2*n*n*n - 9*n*n + 43*n - 78) / 6;

        printf("%d\n",s);
    }
    return 0;
}
