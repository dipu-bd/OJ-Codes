#include <stdio.h>
#include <math.h>

int main()
{
    int test, cas = 1;

    int n, bef, aft, cnt;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);

        cnt = 0;
        bef = 2;
        while(n--)
        {
            scanf("%d", &aft);
            if(aft > bef) cnt += (int)ceil((aft - bef) / 5.0);
            bef = aft;
        }

        printf("Case %d: %d\n", cas++, cnt);
    }

    return 0;
}
