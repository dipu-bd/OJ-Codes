#include <stdio.h>

int GCD(int a, int b)
{
    if(b==0) return a;
    return GCD(b, a%b);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11827_Maximum GCD_01.inp","r",stdin);
    #endif

    char c;
    int n, m, i,j;
    int array[100],t,g;

    scanf("%d ",&n);
    while(n--)
    {
        for(m=0,c=' '; c!='\n'; ++m)
        {
            fseek(stdin, -1, SEEK_CUR);
            scanf(" %d", array+m);
            while((c=getchar())==' ');
        }

        for(g=i=0; i<m-1; ++i)
            for(j=i+1; j<m; ++j)
                if((t=GCD(array[i],array[j]))>g) g=t;

        printf("%d\n",g);
    }

    return 0;
}
