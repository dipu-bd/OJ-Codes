#include <stdio.h>

int m, n;
char land[110][110];

void dfs(int a, int b)
{
    if(a<0 || a>=m) return;
    if(b<0 || b>=n) return;
    if(!land[a][b]) return;

    land[a][b] = 0;

    dfs(a-1, b);
    dfs(a-1, b+1);

    dfs(a, b+1);
    dfs(a+1, b+1);

    dfs(a+1, b);
    dfs(a+1, b-1);

    dfs(a, b-1);
    dfs(a-1, b-1);

    return;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int i, j, count;
    while(scanf(" %d %d", &m, &n)!=EOF && m>0)
    {
        for(i=0; i<m; ++i)
        {
            getchar();
            for(j=0; j<n; ++j)
                land[i][j] = (getchar()=='@');
        }

        for(count=i=0; i<m; ++i)
            for(j=0; j<n; ++j)
                if(land[i][j])
                {
                    dfs(i,j);
                    ++count;
                }

        printf("%d\n",count);
    }

    return 0;
}
