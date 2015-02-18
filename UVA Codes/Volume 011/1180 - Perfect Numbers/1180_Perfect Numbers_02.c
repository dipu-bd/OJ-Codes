#include <stdio.h>

int main()
{
    int n, p;
    scanf ("%d", &n);

    while (n--)
    {
        scanf ("%d,", &p);
        if (p == 2 || p == 3 || p == 5 || p == 7 || p == 13 || p == 17 || p == 19 || p == 31) puts ("Yes");
        else puts ("No");
    }
    return 0;
}
