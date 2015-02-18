#include <stdio.h>

#define SIZE 105
int dept, row, col;
char array[SIZE][SIZE];

void dfs(int i, int j)
{
    if(i < 0 || i >= row || j < 0 || j >= col || array[i][j] == '.') return;

    array[i][j] = '.';
    ++dept;

    dfs(i, j + 1);
    dfs(i, j - 1);

    dfs(i + 1, j + 1);
    dfs(i + 1, j);
    dfs(i + 1, j - 1);

    dfs(i - 1, j + 1);
    dfs(i - 1, j);
    dfs(i - 1, j - 1);

    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("11244_Counting Stars_01.inp", "r", stdin);
#endif

    int i, j, count;
    while(scanf("%d %d", &row, &col) != EOF && row > 0)
    {
        for(i = 0; i < row; ++i)
            scanf(" %[^\n]", array[i]);

        for(count = i = 0; i < row; ++i)
            for(j = 0; j < col; ++j)
                if(array[i][j] == '*')
                {
                    dept = 0;
                    dfs(i, j);
                    if(dept == 1) ++count;
                }

        printf("%d\n", count);
    }

    return 0;
}
