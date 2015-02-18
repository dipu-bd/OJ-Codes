#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef long long ll;

int A[100005];

int main()
{
    int test, cas = 1;

    int n, q, x, a;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &q);

        ll sum = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", A + i);
            sum += (ll)(n - 1 - (i << 1)) * A[i];
        }

        printf("Case %d:\n", cas++);
        while(q--)
        {
            scanf("%d", &x);
            if(x == 1) printf("%lld\n", sum);
            else
            {
                scanf("%d %d", &x, &a);
                sum += (ll)(n - 1 - (x << 1)) * (a - A[x]);
                A[x] = a;
            }
        }
    }

    return 0;
}
