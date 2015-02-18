#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define LIMIT 3000010
#define INF LLONG_MAX
typedef long long LL;
typedef unsigned long long ULL;

LL phi[LIMIT + 10];
LL sum[LIMIT + 10];

void makephi()
{
    phi[2] = 1;
    for(int i = 3; i < LIMIT; ++i) phi[i] = i;

    for(int i = 4; i < LIMIT; i += 2)
        phi[i] -= phi[i] / 2;

    for(int i = 3; i < LIMIT; i += 2)
        if(phi[i] == i)
        {
            --phi[i];
            for(int j = i + i; j < LIMIT; j += i)
                phi[j] -= phi[j] / i;
        }

    for(int i = 2; i < LIMIT; ++i) phi[i] *= i;
}

/*
res[n] = res[n-1] + s[n];
s[n] = n * (-1 + Sum_(d|n){d*phi[d]}) / 2;
*/

void calcsum()
{
    for(int j = 1; j < LIMIT; ++j)
        sum[j] = phi[j];

    for(int i = 2; i < LIMIT; ++i)
    {
        for(int j = i; j < LIMIT; j += i)
            sum[j] += phi[j / i];
        sum[i] = sum[i - 1] + i * (sum[i] / 2);
    }
}

int main()
{
    makephi();
    calcsum();

    int test, cas = 1;
    int n;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        printf("Case %d: %llu\n", cas++, (ULL)sum[n]);
    }

    return 0;
}
