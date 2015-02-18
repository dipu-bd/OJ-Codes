#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef long long ll;

ll rev(ll n)
{
    ll m = 0;
    while(n > 0)
    {
        m = m * 10 + n % 10;
        n /= 10;
    }

    return m;
}

bool islychrel(ll n)
{
    n += rev(n);
    for(int i = 0; i < 55; ++i)
    {
        ll m = rev(n);
        if(m == n) return false;
        n += m;
    }

    return true;
}

int main()
{
    int cnt = 0;

    for(int i = 1; i <= 10000; ++i)
        if(islychrel(i)) cnt++;

    printf("%d\n", cnt);

    return 0;
}
