/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
#include <stdio.h>
//typedefs
typedef long long ll;
typedef unsigned long long ull;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

ll fib[50];

int getlen(ll num)
{
    if(num == 0)
        return 0;

    REP(i, 0, 50)
    if(num < fib[i])
        return i - 2;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    //pregen
    fib[0] = 0;
    fib[1] = 1;
    REP(i, 2, 50)
    fib[i] = fib[i - 1] + fib[i - 2];

    int n;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        
        int p = getlen(n);
        while(p > 0)
        {
            putchar('1');
            n -= fib[p + 1];
            int q = getlen(n);
            REP(i, q + 1, p) putchar('0');
            p = q;
        }
        putchar('\n');
    }

    return 0;
}



