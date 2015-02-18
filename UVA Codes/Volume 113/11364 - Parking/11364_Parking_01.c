#include <stdio.h>

#define MAX 100
#define MIN 0

int main()
{
    int t, n, x, max, min;
    scanf("%d", &t);

    while(t--)
    {
        max = MIN, min = MAX;

        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &x);
            if(x > max) max = x;
            if(x < min) min = x;
        }

        printf("%d\n", (max - min) << 1);
    }

    return 0;
}
