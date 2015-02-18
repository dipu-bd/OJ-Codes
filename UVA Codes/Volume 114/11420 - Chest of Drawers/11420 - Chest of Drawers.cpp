#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

ll ways[70][70][2];

ll recur(int n, int l, char lock)
{
    if(l < 0) return 0;
    if(n == 0)
    {
        if(l == 0) return 1;
        else return 0;
    }

    ll& p = ways[n][l][lock];
    if(p != -1) return p;

    p = recur(n - 1, l, 0);
    if(lock == 1)
        p += recur(n - 1, l - 1, 1);
    else
        p += recur(n - 1, l, 1);

    return p;
}

int main()
{
    ll way;
    int n, s;
    memset(ways, -1, sizeof(ways));
    while(scanf("%d %d", &n, &s) != EOF && n >= 0)
    {
        way = recur(n, s, 1);
        printf("%lld\n", way);
    }

    return 0;
}
