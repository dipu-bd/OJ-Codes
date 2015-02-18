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
using namespace std;

int main()
{
    int way[300];
    memset(way, 0, sizeof(way));
    int coin[8] = {1, 2, 5, 10, 20, 50, 100, 200};

    way[0] = 1;
    for(int i = 0; i < 8; ++i)
        for(int j = coin[i]; j <= 200; ++j)
            way[j] += way[j - coin[i]];

    printf("%d\n", way[200]);

    return 0;
}

