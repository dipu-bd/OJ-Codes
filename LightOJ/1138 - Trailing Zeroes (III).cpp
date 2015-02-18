#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int res, test, cas = 1;
    int low, high, mid;
    int n, q, cnt;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &q);
        low = 0, high = 1 << 30;
        while(low < high)
        {
            mid = (low + high) / 2;
            for(cnt = 0, n = mid; n;) cnt += (n /= 5);
            if(cnt == q) break;
            else if(cnt < q) low = mid + 1;
            else high = mid - 1;
        }

        printf("Case %d: ", cas++);
        if(cnt != q) printf("impossible\n");
        else printf("%d\n", mid - mid % 5);
    }

    return 0;
}

