#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define SIZE 5000010
bool flag[SIZE + 10];

typedef unsigned long long ULL;
ULL phi[SIZE + 10];

void calc_phi()
{
    for(int i = 2; i < SIZE; ++i) phi[i] = i;

    phi[2] = 1;
    for(int i = 4; i < SIZE; i += 2)
    {
        flag[i] = 1;
        phi[i] -= phi[i] >> 1;
    }

    for(int i = 3; i < SIZE; i += 2)
        if(!flag[i])
        {
            --phi[i];
            for(int j = i + i; j < SIZE; j += i)
            {
                flag[j] = 1;
                phi[j] -= phi[j] / i;
            }
        }

    for(int i = 2; i < SIZE; ++i)
            phi[i] = phi[i] * phi[i];

    for(int i = 2; i < SIZE; ++i)
        phi[i] += phi[i - 1];
}

int main()
{
    calc_phi();

    int test, cas = 1;
    int a, b;
    ULL res;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &a, &b);
        res = phi[b] - phi[a - 1];
        printf("Case %d: %llu\n", cas++, res);
    }

    return 0;
}

