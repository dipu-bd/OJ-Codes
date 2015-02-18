#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char inp[1010];
int save[1010];
int len;

bool ispalin(int st, int et)
{
    while(st < et)
        if(inp[st++] != inp[et--])
            return false;
    return true;
}

int dp(int pos)
{
    if(pos >= len) return 0;

    if(save[pos]) return save[pos];

    int rt = 1 + dp(pos + 1);
    for(int i = pos + 1; i < len; ++i)
    {
        if(ispalin(pos, i))
        {
            int t = 1 + dp(i + 1);
            if(t < rt) rt = t;
        }
    }

    return (save[pos] = rt);
}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", inp);

        memset(save, 0, sizeof(save));
        len = strlen(inp);
        int res = dp(0);

        printf("Case %d: %d\n", cas++, res);
    }

    return 0;
}
