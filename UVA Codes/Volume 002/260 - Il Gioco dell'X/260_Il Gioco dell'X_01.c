#include <stdio.h>

#define MAX 200
int lim;
char flag;
char board[MAX][MAX];

void dfs(int i, int j)
{
    if(i<0 || j<0 || i>=lim || j>=lim || board[i][j]=='w') return;

    if (i>=lim-1) { flag = 1; return; }

    board[i][j] = 'w';

    dfs(i-1,j-1);
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i,j+1);
    dfs(i+1,j);
    dfs(i+1,j+1);

    return;
}

int main()
{
    int i, c;

    for(c=1; scanf("%d",&lim)!=EOF && lim; ++c)
    {
        for(i=0; i<lim; ++i)
            scanf(" %s", board[i]);

        for(i=flag=0; i<lim && !flag; ++i)
        {
            flag=0;
            dfs(0, i);
        }

        if(flag)  printf("%d B\n",c);
        else printf("%d W\n",c);
    }

    return 0;
}
