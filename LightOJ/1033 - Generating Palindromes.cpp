#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
using namespace std;

char inp[110];
int save[110][110];

int recur(int i, int j)
{
    if(i>=j) return 0;

    int& s = save[i][j];
    if(s >= 0) return s;

    if(inp[i] == inp[j])
        s = recur(i + 1, j - 1);
    else
        s = 1 + min(recur(i, j - 1), recur(i + 1, j));

    return s;
}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", inp);
        memset(save, -1, sizeof(save));
        int r = recur(0, strlen(inp) - 1);
        printf("Case %d: %d\n", cas++, r);
    }

    return 0;
}
