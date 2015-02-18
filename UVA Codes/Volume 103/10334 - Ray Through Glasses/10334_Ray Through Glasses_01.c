#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1001

char *fib[MAX];

char *add(char *a, char *b)
{
    int l1, l2, l, t, s;
    l1 = strlen(a);
    l2 = strlen(b);
    l = l1 + 1;

    char *res = malloc((l+2)*sizeof(char));
    res[l] = t =0;

    while(l--)
    {
        s = (l1>0) ? a[--l1]-'0' : 0;
        s += (l2>0) ? b[--l2]-'0' : 0;
        s += t;
        t = s/10;
        res[l] = (s - t*10) + '0';
    }

    while(res[0]=='0') ++res;
    return res;
}

int main()
{
    int i, n;

    fib[0] = "1", fib[1] = "2";
    for(i=2;i<MAX;++i)
        fib[i] = add(fib[i-1],fib[i-2]);

    while(scanf("%d",&n)!=EOF)
        puts(fib[n]);

    return 0;
}
