#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long ull;

int main()
{
    freopen("11319.inp", "w", stdout);

    int n = 4;
    int A[100][7] =
    {
        { 0, 0, 0, 0, 0, 0, 0},
        { 1, 0, 0, 0, 0, 0, 0},
        { 650, 120, 150, 120, 1000, 928, 3 },
        { 1000, 1000, 1000, 1000, 1000, 455, 10 }
    };

    printf("%d\n", n);

    for(int i = 0; i < n; ++i)
    {
        for(int x = 1; x <= 1500; ++x)
        {
            ull res = 0;
            for(int p = 6; p >= 0; --p)
                res = (res * x) + A[i][p];

            printf("%llu\n", res);
        }
    }

    return 0;
}
