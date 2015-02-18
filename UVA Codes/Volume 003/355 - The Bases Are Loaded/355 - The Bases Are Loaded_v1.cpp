// C header files
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

long long power(int a, int n)
{
    if(n == 0) return 1;
    if(n & 1)
    {
        long long res = power(a, (n - 1) >> 1);
        return res * res * a;
    }
    else
    {
        long long res = power(a, n >> 1);
        return res * res;
    }

}

void convert(long long dec, int base)
{
    if(dec)
    {
        lldiv_t res = lldiv(dec, base);
        convert(res.quot, base);
        char ch = res.rem ;
        ch += ch < 10 ? '0' : 'A' - 10;
        putchar(ch);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("355.inp", "r", stdin);
#endif
    int a, b;
    char num[100];
    long long dec;

    while(scanf(" %d %d %s", &a, &b, num)!=EOF)
    {
        //convert to decimal
        for(int i = dec = 0, ch, j = strlen(num); j--; ++i)
        {
            ch = num[i];
            ch -= isdigit(ch) ? '0' : 'A' - 10;
            if(ch >= a) goto invalid_base;
            dec += power(a, j) * ch;
        }

        //recursive convert from decimal
        printf("%s base %d = ", num, a);
        if(b == 10) printf("%lld", dec);
        else if(dec) convert(dec, b);
        else putchar('0');

        printf(" base %d\n", b);
        continue;

invalid_base:   //if base of number is invalid
        printf("%s is an illegal base %d number\n", num, a);
    }

    return 0;
}
