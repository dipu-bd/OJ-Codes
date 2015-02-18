#include <stdio.h>

#define MAX 30

int D;
char img[MAX][MAX];

void dfs(int i, int j)
{
    if(i<0 || j<0 || i>=D || j>=D) return;
    if(img[i][j]=='0') return;

    img[i][j] = '0';

    dfs(i+1, j+1);
    dfs(i+1, j);
    dfs(i+1, j-1);
    dfs(i, j-1);
    dfs(i, j+1);
    dfs(i-1, j-1);
    dfs(i-1, j);
    dfs(i-1, j+1);

    return;
}

int main()
{
    int i, j, n, c = 1;
    while(scanf("%d", &D)!=EOF)
    {
        for(i=0; i<D; ++i)
            scanf(" %[01]", img[i]);

        for(i=n=0; i<D; ++i)
            for(j=0; j<D; ++j)
                if(img[i][j]=='1')
                    dfs(i,j), ++n;

        printf("Image number %d contains %d war eagles.\n", c++, n);
    }

    return 0;
}
