#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

int n;
int pin[18][18];
int save[100000];

inline void setmax(int& a, const int& b)
{
    if(a < b) a = b;
}

int recur(bitset<18> take = 0)
{
    int& p = save[(int)take.to_ulong()];
    if(p > 0) return p;

    int mx = 0;
    int r = take.count();
    for(int i = 0; i < n; ++i)
    {
        if(!take[i])
        {
            take.set(i, 1);
            setmax(mx , pin[r][i] + recur(take));
            take.set(i, 0);
        }
    }

    return p = mx;
}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", pin[i] + j);

        memset(save, 0, sizeof(save));
        printf("Case %d: %d\n", cas++, recur());
    }

    return 0;
}
