#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

int main()
{
    freopen("10400.inp", "w", stdout);

    srand(clock());

    int bound = 32001;

    int t = 25;
    int n = 100;

    printf("%d\n", t);
    while(t--)
    {
        printf("%d", n);
        for(int i = 0; i < n; ++i)
        {
            printf(" %d", (rand() % bound));
        }
        printf(" %d\n", (rand() % bound));
    }

    return 0;
}
