#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int mes;
    char data[50];
} DICT;

DICT dic[100];

int compare (const DICT *a, const DICT *b)
{
    return (a->mes) - (b->mes);
}

int GetData (int pos)
{
    scanf (" %[^\n]", dic[pos].data);

    char *a = dic[pos].data;
    int i, j, mes = 0;
    for (i = 0; a[i]; ++i)
        for (j = i + 1; a[j]; ++j)
            if (a[i] > a[j]) ++mes;

    dic[pos].mes = mes;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("612_DNA Sorting_01.inp", "r", stdin);
#endif

    int tc, n, m, i;
    scanf ("%d", &tc);

    while (tc--)
    {
        scanf ("%d %d", &n, &m);
        for (i = 0; i < m; ++i) GetData (i);

        qsort (dic, i, sizeof (DICT), compare);
        for (i = 0; i < m; ++i) puts(dic[i].data);

        if (tc > 0) putchar ('\n');
    }

    return 0;
}
