/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
#include <stdio.h>

int test, cas = 1;

int main()
{
    int n, m, k;
    double p, ans;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d %lf", &n, &m, &k, &p);
        ans = (p * n) * k;
        printf("Case %d: %.8lf\n", cas++, ans);
    }

    return 0;
}
