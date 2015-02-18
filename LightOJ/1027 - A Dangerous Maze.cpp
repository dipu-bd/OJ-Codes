/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
#include <stdio.h>
#include <algorithm>
using namespace std;

int test, cas = 1;

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);

    int n, x, sum, ncnt;
    while(test--)
    {
        scanf("%d", &n);

        sum = ncnt = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &x);
            if(x >= 0) sum += x;
            else sum -= x, ++ncnt;
        }

        printf("Case %d: ", cas++);

        if(n == ncnt)
        {
            printf("inf\n");
            continue;
        }

        n -= ncnt;
        x = __gcd(sum, n);
        sum /= x, n /= x;

        printf("%d/%d\n", sum, n);
    }

    return 0;
}
