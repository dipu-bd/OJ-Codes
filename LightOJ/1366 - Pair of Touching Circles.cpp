#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int test, cas = 1;

    int x, y;
    typedef long long ll;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &x, &y);

        ll sum = 0, tmp = 1, ss;
        for(int i = 2; i <= y; i += 2)
        {
            tmp = y - i + 1;
            ss = (x < 2 * i) ? 0 : x - 2 * i + 1;
            sum += tmp * ss;
        }
        for(int i = 2; i <= x; i += 2)
        {
            tmp = (x < i) ? 0 : x - i + 1;
            ss = (y < 2 * i) ? 0 : y - 2 * i + 1;
            sum += tmp * ss;
        }

        printf("Case %d: %lld\n", cas++, sum);
    }

    return 0;
}
