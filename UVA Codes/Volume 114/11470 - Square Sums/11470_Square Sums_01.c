#include <stdio.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("11470_Square Sums_01.inp", "r", stdin);
#endif

    long long a[12][12], sum;
    int n, hn, i, j, k, c = 1;
    while(scanf("%d", &n) != EOF && n > 0)
    {
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                scanf("%lld", a[i] + j);

        printf("Case %d:", c++);

        hn = n >> 1, --n;
        for(i = 0, j = n; i < hn; ++i, --j)
        {
            for(sum = 0, k = i + 1; k < j; ++k)
                sum += a[i][k] + a[k][i] + a[k][j] + a[j][k];
            sum += a[i][i] + a[j][j] + a[i][j] + a[j][i];
            printf(" %lld", sum);
        }

        if(i == j) printf(" %lld\n", a[i][j]);
        else putchar('\n');
    }

    return 0;
}

