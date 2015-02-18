#include <stdio.h>
#include <stdlib.h>

char inp[2000010];

int compare(const char *a, const char *b)
{
    return (*a - *b);
}

int main()
{
    int n, i;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;++i) scanf("%d", &inp[i]);
        qsort(inp, n, sizeof(char), compare);
        for(i=0;i<n-1;++i) printf("%d ", inp[i]);
        printf("%d\n", inp[n-1]);
    }
    return 0;
}
