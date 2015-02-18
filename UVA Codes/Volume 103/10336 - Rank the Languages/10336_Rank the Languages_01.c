#include <stdio.h>
#include <string.h>

#define SIZE 500

int row, col;
char array[SIZE][SIZE];

void dfs(int i, int j, char t)
{
    if(i < 0 || j < 0 || i >= row ||
            j >= col || array[i][j] != t) return;

    array[i][j] = 0;

    dfs(i, j - 1, t);
    dfs(i, j + 1, t);
    dfs(i - 1, j, t);
    dfs(i + 1, j, t);

    return;
}


typedef struct
{
    char nam;
    int count;
} LANG;

LANG lang[30];
int increase(int max, char t)
{
    int i;
    for(i = 0; i < max; ++i)
        if(lang[i].nam == t)
        {
            ++lang[i].count;
            return max;
        }

    lang[max].nam = t;
    ++lang[max].count;
    return ++max;
}

int compare(const LANG* a, const LANG* b)
{
    if((b->count) != (a->count))
        return (b->count) - (a->count);
    return (a->nam) - (b->nam);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10336_Rank the Languages_01.inp", "r", stdin);
#endif
    char t, max;
    int tc, n, i, j;

    scanf("%d", &tc);
    for(n=1; tc--; ++n)
    {
        scanf("%d %d", &row, &col);

        for(i = 0; i < row; ++i)
            scanf(" %[^\n]", array[i]);

        memset(lang, 0, sizeof(lang));

        for(i = max = 0; i < row; ++i)
            for(j = 0; j < col; ++j)
            {
                t = array[i][j];
                if(t)
                {
                    max = increase(max, t);
                    dfs(i, j, t);
                }
            }

        qsort(lang, max, sizeof(LANG), compare);

        printf("World #%d\n", n);
        for(i = 0; i < max; ++i)
            printf("%c: %d\n", (lang + i)->nam, (lang + i)->count);

    }

    return 0;
}
