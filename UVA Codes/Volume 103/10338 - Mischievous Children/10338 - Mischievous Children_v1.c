#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char inp[30];
char letter[30];

long long fact(long long n)
{
    if(n < 2) return 1;
    return n * fact(n - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10338.inp", "r", stdin);
#endif

    int n, i, t;
    long long res;

    scanf("%d", &n);
    for(t = 1; n--; ++t)
    {
        scanf(" %s", inp);
        memset(letter, 0, sizeof(letter));

        for(i = 0; inp[i]; ++i)
            ++letter[inp[i] - 'A'];

        res = fact(i);
        for(i = 0; i < 26; ++i)
            if(letter[i] > 1) res /= fact(letter[i]);

        printf("Data set %d: %lld\n", t, res);
    }

    return 0;
}
