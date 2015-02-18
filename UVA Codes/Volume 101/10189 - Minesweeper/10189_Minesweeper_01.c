#include <stdio.h>

int main()
{
    int m,n;
    register int i,j,k,l,c,f=0;
    char inp[110][110];
    while(scanf(" %d %d",&m,&n)!=EOF)
    {
        if(m==0 && n==0) break;

        for(i=0; i<m; i++)
            scanf(" %[^\n]",inp[i]);

        if(f!=0) putchar('\n');
        printf("Field #%d:\n",++f);

        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(inp[i][j]=='*')
                {
                    putchar('*');
                    continue;
                }

                for(c=0,k=-1; k<=1; k++)
                {
                    if(i<k || i-k>=m) continue;
                    for(l=-1; l<=1; l++)
                    {
                        if(j<l || j-l>=n) continue;
                        c+=(inp[i-k][j-l]=='*');
                    }
                }

                printf("%d",c);
            }
            putchar('\n');
        }
    }
    return 0;
}
