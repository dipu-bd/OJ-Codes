#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;

ll save[32][32][32];
ll dp(int n, int m, int k)
{
    if(k == 0) return 1;
    if(n < 0 || m < 0) return 0;

    if(save[n][m][k] > 0)
        return save[n][m][k];

    ll res = 0;
    for(int i = 1; i <= n; ++i)
        res += m * dp(n - i, m - 1, k - 1);

    return (save[n][m][k] = res);

}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        int n, k;
        scanf("%d %d", &n, &k);

        printf("Case %d: ", cas++);
        if(k > n)
        {
            printf("0\n");
            continue;
        }

        ll ways = dp(n, n, k);
        printf("%lld\n", ways);
    }

    return 0;
}
