#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max = 5;
char *fib[50];

void *add(char *num1, char *num2)
{
    char *res;
    char a, b, s, t;
    int l1, l2, l;

    l1 = strlen(num1) - 1;
    l2 = strlen(num2) - 1;
    l = 3 + ((l1 > l2) ? l1 : l2);

    res = (char*)malloc(l * sizeof(char));
    res[--l] = t = 0;
    while(l >= 0)
    {
        a = (l1 >= 0) ? num1[l1--] : '0';
        b = (l2 >= 0) ? num2[l2--] : '0';
        s = a + b + t - ('0' << 1);
        t = s / 10;
        res[--l] = s - t * 10 + '0';
    }

    while(*res == '0') ++res;
    return res;
}

int main()
{
    fib[0] = "1", fib[1] = "1";
    fib[2] = "2", fib[3] = "3";
    fib[4] = "5", fib[5] = "8";

    int n;
    while(scanf("%d", &n) != EOF && n > 0)
    {
        for(; max <= n; ++max)
            fib[max] = add(fib[max - 1], fib[max - 2]);

        puts(fib[n]);
    }

    return 0;
}
