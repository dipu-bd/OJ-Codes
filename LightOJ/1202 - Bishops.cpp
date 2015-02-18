#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int test, cas = 1;

    int r1, c1, r2, c2, sum1, sum2;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        sum1 = r1 + c1;
        sum2 = r2 + c2;

        printf("Case %d: ", cas++);
        if((sum1 % 2) != (sum2 % 2)) puts("impossible");
        else if(abs(r1 - r2) == abs(c1 - c2)) puts("1");
        else puts("2");
    }

    return 0;
}
