#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#define MAX 50000

vector<int> num[MAX + 5];

void precalc()
{
    int lm = sqrt(MAX);
    for(int a = 0; a <= lm; ++a)
    {
        for(int b = a; b <= lm; ++b)
        {
            for(int c = b; c <= lm; ++c)
            {
                int n = a * a + b * b + c * c;
                if(n > MAX) break;
                if(num[n].empty())
                {
                    num[n].push_back(a);
                    num[n].push_back(b);
                    num[n].push_back(c);
                }
            }
        }
    }
}

int main()
{
#ifdef DIPU
    freopen("11342.inp", "r", stdin);
#endif

    precalc();

    int n, k;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &k);
        if(num[k].empty()) puts("-1");
        else printf("%d %d %d\n", num[k][0],
                        num[k][1], num[k][2]);
    }

    return 0;
}
