/* =================================
@AUTHOR : Sudipto Chandra Das DIPU
@UNIV : SUST [2012-331-019]
@COUNTRY : Bangladesh
================================= */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <bitset>
using namespace std;

//main function
int main()
{
#ifdef LOCAL
    freopen("948.inp", "r", stdin);
#endif // LOCAL

    typedef long long ll;

    //precalc
    int fib[50];
    const int len = 42;
    fib[0] = 1, fib[1] = 2;
    for(int i = 2; i <= len; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    //takeinp
    int test, n, sum;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);

        sum = 0;
        bitset<50> bit(0);
        for(int i = len; i >= 0; --i)
        {
            if(!bit[i + 1] && sum + fib[i] <= n)
            {
                sum += fib[i];
                bit[i] = true;
                if(sum == n) break;
            }
        }

        string s = bit.to_string();
        const char* p = s.data();
        while(*(p + 1) && *p == '0') ++p;
        printf("%d = %s (fib)\n", sum, p);
    }

    return 0;
}
