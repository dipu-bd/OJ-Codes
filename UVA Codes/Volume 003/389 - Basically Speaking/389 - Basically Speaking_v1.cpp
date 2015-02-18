// C header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 9999999

int power(int a, int n)
{
    if(!n) return 1;
    if(n & 1)
    {
        int res = power(a, (n - 1) >> 1);
        return res * res * a;
    }
    else
    {
        int res = power(a, n >> 1);
        return res * res;
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("389.inp", "r", stdin);
#endif

    char num[10], res[10];
    int a, b, dec;

    while(scanf(" %s %d %d", num, &a, &b) != EOF)
    {
        //convert to decimal
        for(int i = dec = 0, j = strlen(num), ch; j--; ++i)
        {
            ch = num[i];
            ch -= isdigit(ch) ? '0' : 'A' - 10;
            dec += ch * power(a, j);
        }

        if(b == 10)
            if(dec > MAX) puts("  ERROR");
            else printf("%7d\n", dec);
        else if(dec == 0) puts("      0");
        else
        {
            //convert from decimal
            for(int i = 6, ch; i >= 0; i--)
            {
                if(dec)
                {
                    div_t d = div(dec, b);
                    dec = d.quot;
                    ch = d.rem;
                    ch += ch < 10 ? '0' : 'A' - 10;
                    res[i] = ch;
                }
                else res[i] = ' ';
            }

            //show result
            if(dec) puts("  ERROR");
            else {res[7] = 0;  puts(res); }
        }

    }

    return 0;
}
