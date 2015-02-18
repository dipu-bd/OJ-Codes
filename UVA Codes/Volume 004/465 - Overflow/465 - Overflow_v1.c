#include <stdio.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("465.inp", "r", stdin);
#endif

    char c;
    char inp[500];
    long long a, b, r;
    long long mask = ~(0x7FFFFFFFLL);

    while(gets(inp))
    {
        sscanf(inp, "%lld %c %lld", &a, &c, &b);
        r = (c == '*') ? a * b : a + b;
        puts(inp);
        if(a & mask) puts("first number too big");
        if(b & mask) puts("second number too big");
        if(r & mask) puts("result too big");
    }

    return 0;
}
