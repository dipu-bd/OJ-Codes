#include <stdio.h>
#include <math.h>

int main()
{
    char t;
    int tc, r, c;

    scanf("%d", &tc);
    while(tc--)
    {
        scanf(" %c %d %d", &t, &r, &c);

        if(t == 'r' || t == 'Q')
            printf("%d\n", (r < c) ? r : c);
        else if(t == 'k')
            printf("%d\n", (int)(ceil(r * 0.5) * ceil(c * 0.5) + floor(r * 0.5) * floor(c * 0.5)));
        else if(t == 'K')
            printf("%d\n", (int)(ceil(r * 0.5) * ceil(c * 0.5)));
    }

    return 0;
}
