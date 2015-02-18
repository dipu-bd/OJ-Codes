#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nums[60][30];

int comp(const char* a, const char* b)
{
    register char c, d;
    register int i, j, l1, l2;
    l1 = strlen(a);
    l2 = strlen(b);
    for(i = j = 0; a[i] || b[j]; ++i, ++j)
    {
        c = (i < l1) ? a[i] : b[i - l1];
        d = (j < l2) ? b[j] : a[j - l2];
        if(c != d) return (c - d);
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10905.inp", "r", stdin);
#endif

    int n, i;
    while(scanf("%d", &n) != EOF && n > 0)
    {
        for(i = 0; i < n; ++i)
            scanf(" %s", nums[i]);

        qsort(nums, n, 30, comp);

        for(i = n-1; i >= 0; --i) printf(nums[i]);
        putchar('\n');
    }

    return 0;
}
