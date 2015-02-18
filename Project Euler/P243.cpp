#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <limits.h>
#include <stdarg.h>
using namespace std;

#define MAX 300000000

int phi[MAX];
bool flag[MAX];

int main()
{
    for(int i = 1; i < MAX; ++i) phi[i] = i;

    phi[2] = 1;
    for(int i = 4; i < MAX; i += 2)
    {
        flag[i] = 1;
        phi[i] -= phi[i] / 2;
    }

    for(int i = 3; i < MAX; i += 2)
    {
        if(!flag[i])
        {
            --phi[i];
            for(int j = i + i; j < MAX; j += i)
            {
                flag[j] = 1;
                phi[j] -= phi[j] / i;
            }
        }
    }

    int d = -1;
    double ma = 15499.0 / 94744.0;
    for(int i = 1; i < MAX; ++i)
    {
        double r = phi[i];
        r /= i - 1;
        if(r < ma)
        {
            d = i;
            break;
        }
    }

    if(d < 0) puts("NOTHING FOUND");
    else printf("%d\n", d);

    return 0;
}
