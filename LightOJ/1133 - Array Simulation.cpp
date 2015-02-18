#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    int test, cas = 1;

    char c;
    int n, m, x, y;
    ll arr[150];

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; ++i)
            scanf("%lld", arr + i);

        while(m--)
        {
            scanf(" %c", &c);
            if(c == 'R')
                reverse(arr, arr + n);
            else if(c == 'P')
            {
                scanf("%d %d", &x, &y);
                swap(arr[x], arr[y]);
            }
            else
            {
                scanf("%d", &x);
                if(c == 'S')
                    for(int i = 0; i < n; ++i) arr[i] += x;
                else if(c == 'M')
                    for(int i = 0; i < n; ++i) arr[i] *= x;
                else if(c == 'D')
                    for(int i = 0; i < n; ++i) arr[i] /= x;
            }
        }

        printf("Case %d:\n", cas++);
        bool spc = false;
        for(int i = 0; i < n; ++i)
        {
            if(spc) putchar(' ');
            else spc = true;

            printf("%lld", arr[i]);
        }
        putchar('\n');
    }

    return 0;
}
