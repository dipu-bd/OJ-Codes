#include <stdio.h>

short mask;
void tobin(short n)
{
    mask = 1<<12;
    while(mask)
        putchar(((n & mask)!=0) + '0'), mask>>=1;

    return;
}

int main()
{
    char op;
    short n,a,b,c;

    scanf("%hd",&n);

    while(n--)
    {
        scanf("%hX %c %hX", &a, &op, &b);
        c=(op=='+') ? a+b : a-b;
        tobin(a);
        printf(" %c ", op);
        tobin(b);
        printf(" = %hd\n",c);
    }

    return 0;
}
/*
5
AAA + BBB
A + 3
BBB - AAA
7 - 3
F - 5
*/
