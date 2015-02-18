#include <stdio.h>
#include <math.h>

long long H(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int i,p;
    long long r;

    p = sqrt(n);
    for(i=1,r=0; i<=p; ++i)
        r+= n/i;
    r <<= 1;

    if(p == n/p) r -= (long long) p*p;
    else r -= (long long) p*(n/(p+1));

    return r;
}

int main()
{

    int t,n;
    scanf("%d",&t);

    while (t--)
    {
        scanf("%d", &n);
        printf("%lld\n", H(n));
    }
    return 0;
}

/*

long long H(int n)
{

    long long result = n;
    int cur_divisor = 2, cur_quoitent, prev_divisor = 1, prev_quoitent = n;
    while (1)
    {
        cur_quoitent = n / cur_divisor;
        result +=
            (long long)(prev_quoitent - cur_quoitent) * prev_divisor;
        if (cur_quoitent >= cur_divisor)
            result += cur_quoitent;
        if (cur_quoitent <= cur_divisor)
            break;
        prev_divisor = cur_divisor++;
        prev_quoitent = cur_quoitent;
    }
    return result;
}

*/
